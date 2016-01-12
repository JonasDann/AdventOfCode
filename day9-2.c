//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "util/general.h"
#include "util/linkedList.h"

char *hasCity(LinkedList *cities, char *city) {
    Element *e = cities->firstElement;
    int i, found;
    while(e != 0) {
        i = 0; found = 0;
        if ((char *)e->value != 0) {
            found = 1;
        }
        while(((char *)e->value)[i] != 0) {
            if (((char *)e->value)[i] != city[i]) {
                found = 0;
                break;
            }
            i++;
        }
        if (found) {
            return e->value;
        }
        e = e->next;
    }
    return 0;
}

typedef struct {
    char *city1;
    char *city2;
    int distance;
} Connection;

LinkedList *findConnectionsFromNotVisited(LinkedList *connections, LinkedList *citiesVisited, char *city) {
    LinkedList *result = createLinkedList();
    Element *e = connections->firstElement;
    while(e != 0) {
        if (city == ((Connection *) e->value)->city1 && hasCity(citiesVisited, ((Connection *) e->value)->city2) == 0) {
            add(result, e->value);
        }
        e = e->next;
    }
    return result;
}

int findShortestDistanceFromCity(char *city, int cityCount, LinkedList *connections, LinkedList *citiesVisited, int currentDistance) {
    int longest = 0, result;
    LinkedList *connectionsFromCity = findConnectionsFromNotVisited(connections, citiesVisited, city);
    LinkedList *newCitiesVisited;
    Element *e = connectionsFromCity->firstElement;
    if (e == 0) {
        if (cityCount == length(citiesVisited)) {
            longest = currentDistance;
        }
    } else {
        while (e != 0) {
            newCitiesVisited = duplicateLinkedList(citiesVisited);
            add(newCitiesVisited, ((Connection *) e->value)->city2);
            result = findShortestDistanceFromCity(((Connection *) e->value)->city2, cityCount, connections,
                                                  newCitiesVisited, currentDistance + ((Connection *) e->value)->distance);
            free(newCitiesVisited);
            if (result > longest) {
                longest = result;
            }
            e = e->next;
        }
    }
    return longest;
}

int findShortestDistanceOfCities(LinkedList *cities, LinkedList *connections) {
    int longest = 0, result;
    LinkedList *citiesVisited;
    Element *e = cities->firstElement;
    while(e != 0) {
        citiesVisited = createLinkedList();
        add(citiesVisited, e->value);
        result = findShortestDistanceFromCity((char *) e->value, length(cities), connections, citiesVisited, 0);
        free(citiesVisited);
        if (result > longest) {
            longest = result;
        }
        e = e->next;
    }
    return longest;
}

int main(int argc, char *argv[]) {
    char *input = getInput(argv[0]);

    clock_t t1, t2;

    t1 = clock();

    int distance, i = 0;
    LinkedList *cities = createLinkedList();
    LinkedList *connections = createLinkedList();
    char *city, *city1, *city2;
    Connection *connection;
    while(input[i] != '\0') {
        city = readString(input, &i, ' ');
        city1 = hasCity(cities, city);
        if (city1 == 0) {
            add(cities, city);
            city1 = city;
        }
        i += 4;
        city = readString(input, &i, ' ');
        city2 = hasCity(cities, city);
        if (city2 == 0) {
            add(cities, city);
            city2 = city;
        }
        i += 3;
        distance = readInteger(input, &i);
        connection = malloc(sizeof(Connection));
        connection->city1 = city1;
        connection->city2 = city2;
        connection->distance = distance;
        add(connections, connection);
        connection = malloc(sizeof(Connection));
        connection->city1 = city2;
        connection->city2 = city1;
        connection->distance = distance;
        add(connections, connection);
        i++;
    }

    distance = findShortestDistanceOfCities(cities, connections);

    Element *e = cities->firstElement;
    while (e != 0) {
        free(e->value);
        e = e->next;
    }
    freeLinkedList(cities);
    e = connections->firstElement;
    while (e != 0) {
        free(e->value);
        e = e->next;
    }
    freeLinkedList(connections);

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The longest distance is %i.", distance);

    free(input);
    return 0;
}


defmodule Day3.Mixfile do
    use Mix.Project

    def project do
        [app: :Day3,
         version: "0.0.1",
         escript: [main_module: Day3]]
    end
end
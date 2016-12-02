defmodule Day2.Mixfile do
    use Mix.Project

    def project do
        [app: :Day2,
         version: "0.0.1",
         escript: [main_module: Day2]]
    end
end
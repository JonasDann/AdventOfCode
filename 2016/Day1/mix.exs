defmodule Day1.Mixfile do
    use Mix.Project

    def project do
        [app: :Day1,
         version: "0.0.1",
         escript: [main_module: Day1]]
    end
end
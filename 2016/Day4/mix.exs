defmodule Day4.Mixfile do
    use Mix.Project

    def project do
        [app: :Day4,
         version: "0.0.1",
         escript: [main_module: Day4]]
    end
end
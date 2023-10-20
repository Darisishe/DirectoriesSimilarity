#include <benchmark/benchmark.h>
#include <graph/graph.h>
#include <vector>
#include <string>
#include <iostream>

int count = 0;

static void BM_Algorithms(benchmark::State& state) {
  static std::vector<std::string> algo_names = {"KPP", "Algo#2", "Algo#3", "Alog#4"};
  static std::vector<std::string> sizes = {"10", "100", "1000", "10000", "100000"};
  for(auto _: state) {
    int algo = state.range(0);
    int graph = state.range(1);
    Graph::Generate(algo, graph);
    state.SetLabel(algo_names[algo - 1] + " Graph size: " + sizes[graph - 1]);
  }
}

BENCHMARK(BM_Algorithms)->ArgsProduct({{ 1, 2, 3, 4 }, {1, 2, 3, 4, 5}})->Unit(benchmark::kMillisecond);


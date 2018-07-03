#include <string>
#include <thread>
#include <chrono>
#include <memory>

#include "terminal.hpp"
#include "style.hpp"
#include "image.hpp"
#include "reflow.hpp"
#include "text.hpp"
#include "stacklayout.hpp"
#include "flowlayout.hpp"
#include "progress.hpp"
#include "maxwidth.hpp"

using namespace rxterm;

auto renderToTerm = [](auto const& vt, unsigned const w, Component const& c) {
  // TODO: get actual terminal width
  return vt.flip(c.render(w).toString());
};

int main() {

  using namespace std::chrono_literals;
  using namespace std::string_literals;

  VirtualTerminal vt;

  auto superProgressBar = [](auto x, auto y, auto z) -> FlowLayout<> {
    return {
      Text("3 segment progressbar: "),
      FlowLayout<>{
        MaxWidth(20, Progress(x)),
        MaxWidth(20, Progress(y)),
        MaxWidth(20, Progress(z))
      }
    };
  };

  for (int i = 0; i < 101; ++i) {
    vt = renderToTerm(vt, 80, superProgressBar(0.01 * i, 0.02 * i, 0.03 * i));
    std::this_thread::sleep_for(200ms);
  }

  return 0;
}
// Copyright (C) 2018 Amir Baserinia

// The lambda function `Print` can print any type so long as the
// type supports the `operator<<`.

#include <iostream>
#include <array>

auto Print = [](auto&&... args) {
    std::array<int,sizeof...(args)>{(std::cout << args << ' ',0)...};
};

int main() {
    Print(2, 3.0, "abc", true, 'c');
}

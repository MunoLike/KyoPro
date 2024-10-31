FROM mcr.microsoft.com/devcontainers/base:noble

RUN apt update &&\
    apt install -y\
    python3\
    python3-pip\
    nodejs\
    npm\
    build-essential\
    gdb\
    software-properties-common &&\
    add-apt-repository ppa:ubuntu-toolchain-r/test &&\
    apt update &&\
    apt install -y g++-13

RUN pip3 install --break-system-packages online-judge-tools &&\
    npm install -g atcoder-cli

RUN cd cd /usr/include/x86_64-linux-gnu/c++/13/bits/ &&\
    g++-13 -std=c++2b -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer -Wall -Wextra stdc++.h
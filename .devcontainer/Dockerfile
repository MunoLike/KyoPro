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
    apt update &&\
    apt install -y g++

RUN pip3 install --break-system-packages online-judge-tools &&\
    npm install -g atcoder-cli

RUN cd /usr/include/x86_64-linux-gnu/c++/13/bits/ &&\
    g++ -std=c++2b -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer -Wall -Wextra stdc++.h
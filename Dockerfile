FROM ubuntu:18.04

USER root

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y --no-install-recommends apt-utils && \
    apt-get install build-essential software-properties-common wget libboost-all-dev gdb lcov gcovr -y

RUN add-apt-repository ppa:git-core/ppa && \
    add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get install git -y && \
    apt-get install gcc-8 g++-8 -y && \
    rm -f /usr/bin/gcc /usr/bin/g++ && \
    ln -s /usr/bin/gcc-8 /usr/bin/gcc && \
    ln -s /usr/bin/g++-8 /usr/bin/g++

RUN wget -v https://github.com/Kitware/CMake/releases/download/v3.22.4/cmake-3.22.4-linux-x86_64.tar.gz && \
    gunzip cmake-3.22.4-linux-x86_64.tar.gz && \
    tar -xvf cmake-3.22.4-linux-x86_64.tar && \
    cd cmake-3.22.4-linux-x86_64/ && \
    cp -r bin /usr/ && \
    cp -r doc /usr/share/ && \
    cp -r man /usr/share/ && \
    cp -r share /usr/

RUN git clone https://github.com/gabime/spdlog.git && \
    cd spdlog;cmake -Bbuild .;cd build;make -j install

RUN git clone https://github.com/google/googletest.git -b release-1.11.0 && \
    cd googletest;cmake -Bbuild .;cd build;make -j install

RUN rm -r /usr/bin/gcov;ln -s /usr/bin/gcov-8 /usr/bin/gcov

CMD bash

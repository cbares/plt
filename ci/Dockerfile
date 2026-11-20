# Image de build PLT : mêmes paquets que le workflow GitHub Actions (ubuntu-latest = 24.04).
# Sur la VM Jenkins :
#   docker build -t plt-build:24.04 .
FROM ubuntu:26.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential cmake git ca-certificates pkg-config \
        libsfml-dev libboost1.90-all-dev libmicrohttpd-dev libxml2-dev \
        xvfb xauth lcov gcovr \
    && rm -rf /var/lib/apt/lists/*


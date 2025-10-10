FROM debian:stable-slim as plt-base

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    lcov \
    gcovr \
    git

RUN apt-get update && apt-get install -y \
    libsfml-dev \
    libxml2-dev \
    libboost-all-dev

RUN apt-get update && apt-get install -y \
    dia

VOLUME /app

# Set the working directory
WORKDIR /app

# Build the project
RUN mkdir docker-build && cd docker-build && cmake .. && make client

RUN rm -rf docker-build

RUN mkdir docker-build && cd docker-build && cmake .. && make client


# Run the application
CMD ["./bin/client"]

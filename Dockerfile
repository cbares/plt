FROM debian:stable-slim as plt-base

# Set the working directory
WORKDIR /app

COPY ./src .
COPY ./CMakeLists.txt .
COPY ./.gitignore .
COPY ./extern .
COPY ./cmake .
COPY ./CMakeFiles .
COPY ./lib .
COPY ./test .
COPY ./entrypoint.sh .

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


# Build the project

RUN mkdir docker-build && cd docker-build && cmake .. && make client && cd ..

RUN rm -rf docker-build

RUN chmod +x entrypoint.sh

# Run the application
ENTRYPOINT [ "./entrypoint.sh" ]
CMD ["./bin/client", "/bin/sh"]
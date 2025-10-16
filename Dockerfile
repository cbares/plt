FROM debian:stable-slim as plt-base

ARG USERNAME
ARG USER_UID
ARG USER_GID
ARG DISPLAY

# Set the working directory
WORKDIR /app

RUN groupadd --gid $USER_GID $USERNAME && \
    useradd --uid $USER_UID --gid $USER_GID -m $USERNAME

RUN if [ -n "$DISPLAY" ]; then \
        export DISPLAY=$DISPLAY; \
    fi

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
CMD ["tail", "-f", "/dev/null"]
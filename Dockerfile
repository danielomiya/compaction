#--- install requirements to build our artifact
FROM ubuntu:20.04 AS setup

ARG DEBIAN_FRONTEND=noninteractive

RUN apt update && \
    apt install -y build-essential git cmake

#--- compile our artifact
FROM setup AS build

WORKDIR /src
COPY . ./
RUN make build

#--- copy artifact from build and run it
FROM ubuntu:20.04

WORKDIR /app
COPY --from=build /src/build/app/main ./

ENTRYPOINT ["sh", "-c", "./main"]

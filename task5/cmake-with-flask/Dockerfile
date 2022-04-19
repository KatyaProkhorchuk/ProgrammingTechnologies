
FROM gcc:latest as build
WORKDIR opt/techprog
RUN apt-get update &&\
     apt-get install -y cmake build-essential python3 python3-pip
# RUN apt-get install -y python3-pip python3-dev build-essential
RUN apt-get install -y tzdata
# RUN apt-get install -y cmake g++ python3 python3-pip
RUN apt-get -y install python3
RUN pip3 install --upgrade pip
# RUN pip3 install flask
COPY . /opt/techprog
WORKDIR /opt/techprog
RUN cmake . && make && ./bin/C
FROM ubuntu:20.04
RUN useradd -ms /bin/bash tp2022user
USER tp2022user
FROM python:3.9 as builder
WORKDIR /opt/techprog
RUN python3 -m pip install flask


COPY --from=build /opt/techprog .
EXPOSE 8898

# ENTRYPOINT python3 app.py --port=8898 --host=172.17.0.2
# ENTRYPOINT ["python3"]
CMD python3 app.py --port=8898 --host="0.0.0.0"
# ENTRYPOINT ["python3", "app.py", "--port", "8898", "--host", "127.0.0.1"]
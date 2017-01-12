# Mini weather web scrapper

This is a tiny web scrapper which parse weather data (temperature and humidity) from a certain
state. The current application was implemented in C.

## Requirements

- `libcurl dev library`
- `mysql dev library`
- `mysql server`

## Architecture

The project is basically separated in 3 processes:

### Scraper
This process will crawl data from yahooweather page. Once data is analized, it will be stored in a Queue. You can only run this process once an hour for each state (polite crawling)

### Process
This program will open the current queue and then it will insert data to the Database.

### Server
This project contains a native C web-server created to request weather resoruces. Also there's a built in log file which shows ip's and resource's request.

## Usage

1. Use makefile for compiling every process in each directory (e.g make weather, make process, make server).
2. Import the sql dump ("weather.sql").
3. Run ./weather -c YourCountry -s YourState (Inside "Scraper" directory).
4. Run ./queuetosql (Inside "Process" directory).
5. Run ./server -c port.conf (Inside "Server" directory).
6.
7. Have fun!


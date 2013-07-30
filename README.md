gdata-spreadsheets-cpp
======================

Google Spreadsheets API v3.0 for C++

Current state:
* still in very early development...
* build and tested only on Fedora 17 under Eclipse Juno (v4.2.1)

Current dependencies:
* POCO libraries => 1.4.2p1
* GTest => 1.6.0
* GMock => 1.6.0

Additional includes:
* include dir for POCO include files
* include dir for GMock/GTest include files

Additional libraries:
* PocoFoundation
* PocoNet
* PocoNetSSL
* gmock
* gmock_main
* gtest
* gtest_main
* pthread

Additional CXX flags:
* std=c++11

TODO list:
* CMake configuration
* data types: SpreadsheetFeed, WorksheetFeed, Spreadsheet, Worksheet, Row, Cell
* all service queries from Google Spreadsheets v3.0 API

(Maybe) TODO list:
* CPack rpm packaging 
* integration tests
* configuration file (INI format?)

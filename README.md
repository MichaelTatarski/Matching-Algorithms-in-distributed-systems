# NEidI AVA - matching algorithms in PubSub systems

This project is part of the NEiDI course of the winter lecture 2020/2021 at the university of Rostock. The objective of our project is to implement different matching algorithms in a Pub/Sub system and compare them with regard to their time efficiency on a testbed. In order to accomplish that, we will develop a simple data and filter model as well. Our code base attempts to follow the [MISRA](https://www.misra.org.uk/), [SEI CERT](https://wiki.sei.cmu.edu/confluence/display/seccode/SEI+CERT+Coding+Standards) and [CWE](https://cwe.mitre.org/) guidelines (look in the _security_analysis_ folder for further information).

> **Note:** The tool is intended to be used on an embedded Linux system with a GCC compiler. It is not yet supported for other platforms and will probably not compile on other architectures. Please be aware that our tool doesn't provide a command line interface - it merely comes as a simple static library.

## Installation and usage

Even though we are developing with multiple files, we aim for a single-header form of distribution. Hence, you only have to include one single header file to use all the functionality provided by our tool.

Simply follow the steps listed below to integrate it into your own project:

1.  Copy the **libMADS.a** and the **libMADS.h** file from the _release folder_ into your project directory

2.  Include the header file into your source code

3.  Compile your program into an object file and link it against the archive file

If you are using gcc as a compiler, you can link your source code (which already has to be compiled in an object file) with this statement:

```
gcc yourprogram.o libMADS.a
```

## Getting Started

### 1. Creating a simple data model

Before we start using the matching algorithms included in our tool, we need to define a data model and some corresponding filters, which are being used as an input. Creating an empty data model can be done by declaring a pointer variable of the type `DataModel` and allocating memory space by calling `dataModel_create()`

```c
DataModel *newdataModel =  dataModel_create();
```

Now we can add some attributes to our newly created data model. For the sake of simplicity, we will consider a real life example of a temperature notification with the following attributes:

- VendorID (int64): 1234567890

- SensorID (int64): 471108151337

- Temperature (double): 20.45

- Unit (int32): 1 [°C]

- Timestamp (int64): 1606841111

- SensorLabel (text 32, utf8): MyOffice

- Building (text 32, utf8): KZH

- Floor (text 32, utf8): 2

- Room (text 32, utf8): 273

Transferring these attributes into our data model is quite straight forward with the interface provided by our tool. The API supports _INT64_, _INT32_, _DOUBLE_ and _TEXT32_ as valid data types.

```c
dataModel_addAttributeINT64(newdataModel, "VendorID", 1234567890);
dataModel_addAttributeINT64(newdataModel, "SensorID", 471108151337);
dataModel_addAttributeDOUBLE(newdataModel, "Temperature", 20.45);
dataModel_addAttributeINT32(newdataModel, "Unit", 1);
dataModel_addAttributeINT64(newdataModel, "Timestamp", 1606841111);
dataModel_addAttributeTEXT32(newdataModel, "SensorLabel", "MyOffice");
dataModel_addAttributeTEXT32(newdataModel, "Building", "KZH");
dataModel_addAttributeTEXT32(newdataModel, "Floor", "2");
dataModel_addAttributeTEXT32(newdataModel, "Room", "273");
```

### 2. Creating some corresponding filters

At this stage our data model is basically finished. Now it's time to create some corresponding filters. Each filter consists of an arbitrary number of subfilters in our tool. A subfilter comprises an attribute which the user wants to be filtered as well as an operator and a value. The procedure is quite similar to the creation of a data model. First we declare and allocate memory for our filter by calling `filter_create()`, then we add some subfilters to it. Let's say for instance we want to initialize a filter with these properties:

```math
Building = KZH \wedge Floor = 3 \wedge Temperature \geq 18 \wedge Temperature < 22
```

This is how we would express our logical formula with our tool interface:

```c
Filter *newFilter =  filter_create();

filter_addSubFilterTEXT32(newFilter, "Building", EQUALS, "KZH");
filter_addSubFilterTEXT32(newFilter, "Floor", EQUALS, "3");
filter_addSubFilterDOUBLE(newFilter, "Temperature", GREATER_EQUAL, 18);
filter_addSubFilterDOUBLE(newFilter, "Temperature", SMALLER_THAN, 22);
```

However, in most cases we aren't interested in whether or not just one particular filter is matching a data model, but rather if an entire filter list containing multiple filters matches a data model. For that purpose our tool provides an easy-to-use filter list interface:

```c
FilterList *newFilterList =  filterList_create();
filterList_addFilter(newFilterList, newFilter);
```

### 3. Utilizing the matching algorithms

#### Brute-Force algorithm

to be continued

#### Predicate-Counting algorithm

Now we need to create the data structure for our system. For that we need to call the "setUpPredicateCounting" function. This function only needs the filterList in which all subscriptions are stored.
Next, we need to use our new data structure as a parameter to utilize the predicateCounting function. This function is checking which of the given filters inside the filterList is matching to the given notification (newdataModel).
This function is returning a list of booleans in which the index of the boolList is corresponding to the index of the newFilterList.

Example:

```c
NameList *predicateCountingDatastructure = setUpPredicateCounting(newFilterList)
BoolList *predicateCounting(newFilterList, predicateCountingDatastructure, newdataModel)
```

## Running tests and benchmarks

To be continued...

## Notes for developers

Even though our tool is supposed to be created as a low level library in C, we didn't want to reinvent the wheel for every little knickknack. The filter list and data model APIs implement the _utList_ and _UThash_ library created by Troy D. Hanson (_[Link to the User Guide](https://troydhanson.github.io/uthash/userguide.html)_). These libraries are used for native package repositories for a number of Unix-y distros and have been incorporated into commercial software, academic research, and into other open-source software.

Furthermore, pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. Please make sure to update tests as appropriate. A Doxygen documentation will be available, when the project is ready for an early alpha release.

A simple documentation for the APIs can be found inside the **core folder**.

```
├── build
├── src
│   ├── core #core folder containing essential functionality
│   ├── lib
│   └── utility
└── test
```

Furthermore, here is an overview of the current directory content

|          folder name | Content                                                                               |
| -------------------: | :------------------------------------------------------------------------------------ |
|                  src | Source for the MADS tool                                                              |
|    security_analysis | Classes for the intermediate representation of the parsed Phylum and Rule definitions |
| benchmark-experiment | Example projects to demonstrate the usage of the tool                                 |
|                 test | unit tests that are implemented in ceedling                                           |

## License

[MIT](https://choosealicense.com/licenses/mit/)

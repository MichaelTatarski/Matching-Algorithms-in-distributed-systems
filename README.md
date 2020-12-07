# NEidI AVA - matching algorithms in PubSub systems

This project is part of the NEiDI course of the winter lecture 2020/2021. The objective of our project is to implement different matching algorithms in a _Pub/Sub system_ and compare them with regard to their time efficiency on a testbed. In order to accomplish that, we will develop a simple _data and filter model_ as well.

> **Note:** Our tool is intended to be used on an embedded Linux system with a GCC compiler. It is not yet supported for other platforms and will probably not compile on other architectures.

## Installation

Even though we are developing with multiple files, we aim for a single-header form of distribution. Hence, you only have to include one single header file to use all the functionality provided by our tool.

Simply follow the steps listed below to integrate the tool into your own project:

1.  copy the **libMADS.a** and the **libMADS.h** file from the release build/release path into your directionary

2.  include the header file in your source code where you wish to use the interface of our tool

3.  compile your program into an object file and link it against the archive file

## Getting Started

### 1. Creating a simple data model

Before we start using the matching algorithms included in our tool, we need to define a data model and some corresponding filters, which are being used as an input. Creating an empty data model can be done by declaring a pointer variable of the type `DataModel` and allocating memory space by calling `dataModel_create()`

```c

DataModel *newdataModel =  dataModel_create();

```

Now we can add some attributes to our newly created datamodel. For the sake of simplicity, we will consider a real life example of a temperature notifcation with the following attributes:

- VendorID (int64): 1234567890

- SensorID (int64): 471108151337

- Temperature (double): 20.45

- Unit (int32): 1 [°C]

- Timestamp (int64): 1606841111

- SensorLabel (text 32, utf8): MyOffice

- Building (text 32, utf8): KZH

- Floor (text 32, utf8): 2

- Room (text 32, utf8): 273

Transferring these attributes into our data model is quite straight forward with the interface provided by our tool. The API supports INT64, INT32, DOUBLE and TEXT32 as valid data types.

```c

dataModel_addAttributeINT64(newdataModel, "VendorID", 1234567890);

dataModel_addAttributeINT64(newdataModel, "SensorID", 471108151337);

dataModel_addAttributeDOUBLE(newdataModel, "Temperature", 20.45);

dataModel_addAttributeINT32(newdataModel, "Unit", 1);

dataModel_addAttributeINT64(newdataModel, "Timestamp", 1606841111);

dataModel_addAttributeTEXT32(newdataModel, "SensorLabel", MyOffice);

dataModel_addAttributeTEXT32(newdataModel, "Building", KZH);

dataModel_addAttributeTEXT32(newdataModel, "Floor", 2);

dataModel_addAttributeTEXT32(newdataModel, "Room", 273);

```

---

### 2. Creating some corresponding filters

At this stage our datamodel is basically finished. Now its time to create some corresponding filters.

Each filter consists of an arbitrary number of subfilters in our tool. A subfilter contains a predicate which the user wants to be filtered as well as an operator and a value.

The procedure is quite similar to the creation of a datamodel. First we declare and allocate memory for our filter by calling `Filter_create()`, then we add some subfilters to it. Lets say for instance we want to initialise a filter with these properties:

$$
Building = KZH \wedge Floor = 3\wedge Temperature \geq  18 \wedge Temperature < 22
$$

This is how we would express our logical formula with our tool interface:

```c

Filter *newFilter =  Filter_create();



Filter_addSubFilterTEXT32(newFilter, "Building", EQUALS, KZH);

Filter_addSubFilterTEXT32(newFilter, "Floor", EQUALS, 3);

Filter_addSubFilterTEXT32(newFilter, "Temperature", GREATER_EQUAL, 18);

Filter_addSubFilterTEXT32(newFilter, "Temperature", SMALLER_THAN, 22);

```

However, In most cases we aren't interested in whether or not just one particular filter is matching a data model, but rather if an entire filter list containing multiple filters matches a data model.

For that purpose our tool provides an easy-to-use filter list interface.

```c

FilterList *newFilterList =  FilterList_create();

FilterList_addFilter(newFilterList, newFilter);

```

---

### 3. Utilizing the matching algorithms (not yet implemented)

Now we have created all the necassary componenents, which are needed as an input for our matching algorithms.

To be continued...

## Notes for developers

Even though our tool claims to be created as a low level library in C, we didn't want to reinvent the wheel for every little knickknack. The filter list and data model APIs implement the utList and UThash-library created by Troy. These libraries are used for native package repositories for a number of Unix-y distros and have been incorporated into commercial software, academic research, and into other open-source software.

Furthermore, pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. Please make sure to update tests as appropriate. A Doxygen documentation will be available, when the project is ready for an early alpha release.

An extensive documentation for the APIS can be found inside the **core folder**.

## License

[MIT](https://choosealicense.com/licenses/mit/)

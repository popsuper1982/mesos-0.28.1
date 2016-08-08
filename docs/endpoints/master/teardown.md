---
title: Apache Mesos - HTTP Endpoints - /master/teardown
layout: documentation
---
<!--- This is an automatically generated file. DO NOT EDIT! --->

### USAGE ###
>        /master/teardown

### TL;DR; ###
Tears down a running framework by shutting down all tasks/executors and removing the framework.

### DESCRIPTION ###
Please provide a "frameworkId" value designating the running
framework to tear down.
Returns 200 OK if the framework was correctly teared down.
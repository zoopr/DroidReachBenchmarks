#!/bin/bash

function static_mapping {
    echo "Using Androguard:"
    liana --reachable --find-path-to libnative.so@target_fun ./StaticMapping.apk 2> /dev/null
    echo ""
    echo "Using FlowDroid:"
    liana --use-flowdroid --reachable --find-path-to libnative.so@target_fun ./StaticMapping.apk 2> /dev/null
    echo ""
}

function static_mapping_overload {
    echo "Using Androguard:"
    liana --reachable --find-path-to libnative.so@target_fun ./StaticMappingOverload.apk 2> /dev/null
    echo ""
    echo "Using FlowDroid:"
    liana --use-flowdroid --reachable --find-path-to libnative.so@target_fun ./StaticMappingOverload.apk 2> /dev/null
    echo ""
}

if [ "$1" != "" ]; then
    $1
    exit 0
fi

static_mapping
static_mapping_overload

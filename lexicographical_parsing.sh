#!/bin/bash

# this script expected the string argument to resolve the Smallest Subsequence of Distinct Characters test

echo $1 | grep -o . | sort | tr -d "\n" | tr -s 'a-z'

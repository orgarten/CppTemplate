
[![Build Status](https://travis-ci.com/orgarten/CppTemplate.svg?token=eXJkWkQS9zZcNTmszPwu&branch=master)](https://travis-ci.com/github/orgarten/CppTemplate)
# C++Template
Project template for CMake C++ projects. 

## Dependencies
- cmake
- doctest (if ```BUILD_TESTS``` is enabled)
- google benchmark (if ```BUILD_BENCHMARK``` is enabled)

## Structure
| Directory/File | Content                 |
| :------------- | :---------------------:  |
| .github        | templates for pull requests and issues |
| benchmarks     | Benchmarking with google benchmark |
| cmake          | cmake files such as options and configuration template |  
| doc            | documentation + respective configuration files            |  
| examples       | applications based on library in ```myproject/```             |  
| myproject      | code of library             |  
| tests          | test cases for the library             |  
| .clang-format  | clang-format file for consequent formatting             |  
| .gitignore     | gitignore            |  
| .travis.yml    | travisCI configuration |


## TODO
* doxygen + breathe + sphinx for documentation


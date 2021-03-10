# Notes

3 scenes that C++ will call copy constructor:
- function parameter match
- function return values
- explicit call

This leads to workload, reference (`&`) and move constructor could solve this problem.
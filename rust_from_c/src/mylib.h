#pragma once

#ifdef __cplusplus
extern "C" {
#endif
    // int sum_from_rust(int, int);
    // void hello_from_rust();
    void hello();
    unsigned add(unsigned, unsigned);
    void echo(const char* str);
    void call_cb(void (*cb) (const char* str));
#ifdef __cplusplus
}
#endif

#pragma once
#include <iostream>
#include <bitset>
#include <cstdint>

#define UNKNOWN "unknonw"
#define INFINITE "infinite"
#define NORMAL "normal"
#define SUBNORMAL "subnormal"
#define NAN "nan"
#define ZERO "zero"

template <typename T>
void print_number_info(T const number){
    const char unsigned_integer_8 = 'h';
    const char unsigned_integer_32 = 'j';
    const char unsigned_integer_64 = 'm';
    const int size = sizeof(number) * 8;

    std::cout << "Type: " << typeid(T).name() << "; size: " << size << " bits;";
    if(*typeid(T).name() == unsigned_integer_32 || *typeid(T).name() == unsigned_integer_64 || *typeid(T).name() == unsigned_integer_8){
        std::cout << " number: " << std::bitset<size>(number) << std::endl;
    }
    else{
        std::cout << " number: " << number << std::endl;
    }
}

inline uint32_t float_to_bits(float const value){
    float const* value_ptr = &value;
    uint32_t const* bytes_ptr = (uint32_t const*)(value_ptr);
    return *bytes_ptr;
}

inline float bits_to_float(uint32_t const value){
    uint32_t const* value_ptr = &value;
    float const* bytes_ptr = (float const*)(value_ptr);
    return *bytes_ptr;
}

inline uint64_t float_to_bits(double const value){
    double const* value_ptr = &value;
    uint64_t const* bytes_ptr = (uint64_t const*)(value_ptr);
    return *bytes_ptr;
}

inline double bits_to_float(uint64_t const value){
    uint64_t const* value_ptr = &value;
    double const* bytes_ptr = (double const*)(value_ptr);
    return *bytes_ptr;
}

template<typename T>
bool is_finite(T const value){
    if (sizeof(value) == 4){
        uint32_t bit_val = float_to_bits(value);
        uint8_t exponent = bit_val >> 23;
        uint32_t mantissa = bit_val << 9;
        if (mantissa == 0 && (exponent ^ 255 ) == 0){
            return false;
        }   
    }
    else{
        uint64_t bit_val = float_to_bits(value);
        uint64_t exponent = bit_val << 1 >> 53;
        uint64_t mantissa = bit_val << 12;
        if (mantissa == 0 && (exponent ^ 2047) == 0){
            return false;
        }
    }
    return true;
}

template<typename T>
bool is_infinite(T const value){
    return !is_finite(value);
}

template<typename T>
bool is_positive_inf(T const value){
    if (is_finite(value)){
        return false;
    }

    if (sizeof(value) == 4){
        uint32_t bit_val = float_to_bits(value);
        if ((bit_val >> 31) == 0){
            return true;
        }   
    }
    else{
        uint64_t bit_val = float_to_bits(value);
        if ((bit_val >> 63) == 0){
            return true;
        }
    }
    return false;
}

template<typename T>
bool is_negative_inf(T const value){
    if (is_finite(value)){
        return false;
    }

    if (sizeof(value) == 4){
        uint32_t bit_val = float_to_bits(value);
        if ((bit_val >> 31) == 1){
            return true;
        }   
    }
    else{
        uint64_t bit_val = float_to_bits(value);
        if ((bit_val >> 63) == 1){
            return true;
        }
    }

    return false;
}

template<typename T>
bool is_zero(T const value){
    if (sizeof(value) == 4){
        uint32_t bit_val = float_to_bits(value);
        bit_val = bit_val << 1;
        if ((bit_val ^ 0) == 0){
            return true;
        }   
    }
    else{
        uint64_t bit_val = float_to_bits(value);
        bit_val = bit_val << 1;
        if ((bit_val ^ 0) == 0){
            return true;
        }
    }
    return false;
}

template<typename T>
bool is_pos_zero(T const value){
    if(!is_zero(value)){
        return false;
    }

    if (sizeof(value) == 4){
        uint32_t bit_val = float_to_bits(value);
        if ((bit_val >> 31) == 0){
            return true;
        }   
    }
    else{
        uint64_t bit_val = float_to_bits(value);
        if ((bit_val >> 63) == 0){
            return true;
        }
    }
    
    return false;
}

template<typename T>
bool is_neg_zero(T const value){
    if(!is_zero(value)){
        return false;
    }

    if (sizeof(value) == 4){
        uint32_t bit_val = float_to_bits(value);
        if ((bit_val >> 31) == 1){
            return true;
        }   
    }
    else{
        uint64_t bit_val = float_to_bits(value);
        if ((bit_val >> 63) == 1){
            return true;
        }
    }

    return false;
}

template<typename T>
bool is_nan(T const value){
    if (sizeof(value) == 4){
        uint32_t bit_val = float_to_bits(value);
        uint8_t sign = bit_val >> 31;
        uint8_t exponent = bit_val >> 23;
        uint32_t mantissa = bit_val << 9;

        bit_val = bit_val << 1;
        if (sign == 0 && (exponent ^ 255) == 0 && mantissa != 0){
            return true;
        }   
    }
    else{
        uint64_t bit_val = float_to_bits(value);
        uint8_t sign = bit_val >> 63; 
        uint64_t exponent = bit_val << 1 >> 53;
        uint64_t mantissa = bit_val << 12;

        if (sign == 0 && (exponent ^ 2047) == 0 && mantissa != 0){
            return true;
        }  
    }

    return false;
}

template<typename T>
bool is_normal(T const value){
    if(is_infinite(value) || is_nan(value) || is_zero(value)){
        return false;
    }

    if (sizeof(value) == 4){
        uint32_t bit_val = float_to_bits(value);
        uint8_t exponent = bit_val >> 22;
        uint32_t mantissa = bit_val << 9;

        if ((exponent ^ 0) == 0 && mantissa != 0){
            return false;
        }   
    }
    else{
        uint64_t bit_val = float_to_bits(value);
        uint64_t exponent = bit_val << 1 >> 53;
        uint64_t mantissa = bit_val << 12;

        if ((exponent ^ 0) == 0 && mantissa != 0){
            return false;
        }  
    }

    return true;
}

template<typename T>
bool is_subnormal(T const value){
    if(is_infinite(value) || is_nan(value) || is_zero(value)){
        return false;
    }

    return !is_normal(value);
}

template<typename T>
bool is_signed(T const value){
    if (sizeof(value) == 4){
        uint32_t bit_val = float_to_bits(value);
        uint8_t sign = bit_val >> 31;

        if (sign == 1){
            return true;
        }   
    }
    else{
        uint64_t bit_val = float_to_bits(value);
        uint8_t sign = bit_val >> 63;

        if (sign == 1){
            return true;
        }
    }

    return false;
}

template<typename T>
std::string fpclassify(T const value){
    if(is_infinite(value)){
        return INFINITE;
    }
    else if(is_normal(value)){
        return NORMAL;
    }
    else if(is_subnormal(value)){
        return SUBNORMAL;
    }
    else if(is_nan(value)){
        return NAN;
    }
    else if(is_zero(value)){
        return ZERO;
    }

    return UNKNOWN;
}

inline float abss(float value){
    uint32_t bit_val = float_to_bits(value);
    uint8_t sign = bit_val >> 31;
    if (sign == 1){
        return bits_to_float(bit_val << 1 >> 1);
    }
    return value;
}

inline double abss(double value){
    uint64_t bit_val = float_to_bits(value);
    uint8_t sign = bit_val >> 63;
    if (sign == 1){
        return bits_to_float(bit_val << 1 >> 1);
    }
    return value;
}

inline float min(float const value1, float const value2){
    if(is_normal(value1) && is_normal(value2)){
        if(is_signed(value1) || value2){
            if (is_signed(value1)){
                return value1;
            }else {
                return value2;
            }
        }else {
            if ((float_to_bits(value1) & 2147483647) < (float_to_bits(value2) & 2147483647)){  // 2147483647 = 0111 1111 1111 1111 1111 1111 1111 1111 1111 in binary
                return value1;
            }
            else {
                return value2;
            }
        }
    }
    else if(is_normal(value1) ^ is_normal(value2)){
        if (is_nan(value1)){
            return value2;
        }
        else if (is_zero(value1) && (float_to_bits(value2) >> 31) != 1 ){
            return value1;
        }
        else if (is_zero(value1) && (float_to_bits(value2) >> 31) == 1 ){
            return value2;
        }
        else if (is_zero(value2) && (float_to_bits(value1) >> 31) != 1 ){
            return value2;
        }
        else if (is_zero(value2) && (float_to_bits(value1) >> 31) == 1 ){
            return value1;
        }
        else if (is_positive_inf(value1)){
            return value2;
        }
        else if (is_negative_inf(value1)){
            return value1;
        }
    }
    else{
        if(is_nan(value1)){
            return value2;
        }
        else if(is_nan(value2)){
            return value1;
        }
        if (is_subnormal(value1)){
            return value2;
        }
        else if (is_subnormal(value2)){
            return value1;
        }
        if (is_negative_inf(value2)) {
            return value2;
        }
        else if (is_zero(value2) && !is_negative_inf(value1)) {
            return value2;
        }
    }

    return value1;
}

inline double min(double const value1, double const value2){
    if(is_normal(value1) && is_normal(value2)){
        if(is_signed(value1) || value2){
            if (is_signed(value1)){
                return value1;
            }else {
                return value2;
            }
        }
        else{
            if ((float_to_bits(value1) & 9223372036854775807) < (float_to_bits(value2) & 9223372036854775807)){  // 9223372036854775807 = 0111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 in binary
                return value1;
            }
            else {
                return value2;
            }
        }
    }
    else if(is_normal(value1) ^ is_normal(value2)){
        if (is_nan(value1)){
            return value2;
        }
        else if (is_zero(value1) && (float_to_bits(value2) >> 63) != 1 ){
            return value1;
        }
        else if (is_zero(value1) && (float_to_bits(value2) >> 63) == 1 ){
            return value2;
        }
        else if (is_zero(value2) && (float_to_bits(value1) >> 63) != 1 ){
            return value2;
        }
        else if (is_zero(value2) && (float_to_bits(value1) >> 63) == 1 ){
            return value1;
        }
        else if (is_positive_inf(value1)){
            return value2;
        }
        else if (is_negative_inf(value1)){
            return value1;
        }
    }
    else{
        if(is_nan(value1)){
            return value2;
        }
        else if(is_nan(value2)){
            return value1;
        }
        if (is_subnormal(value1)){
            return value2;
        }
        else if (is_subnormal(value2)){
            return value1;
        }
        if (is_negative_inf(value2)) {
            return value2;
        }
        else if (is_zero(value2) && !is_negative_inf(value1)) {
            return value2;
        }
    }

    return value1;
}

inline float max(float const value1, float const value2){
    if(is_normal(value1) && is_normal(value2)){
        if(is_signed(value1) || value2){
            if (is_signed(value1)){
                return value2;
            }else {
                return value1;
            }
        }else {
            if ((float_to_bits(value1) & 2147483647) < (float_to_bits(value2) & 2147483647)){  // 2147483647 = 0111 1111 1111 1111 1111 1111 1111 1111 1111 in binary
                return value2;
            }
            else {
                return value1;
            }
        }
    }
    else if(is_normal(value1) ^ is_normal(value2)){
        if (is_nan(value1)){
            return value2;
        }
        else if (is_zero(value1) && (float_to_bits(value2) >> 31) != 1 ){
            return value2;
        }
        else if (is_zero(value1) && (float_to_bits(value2) >> 31) == 1 ){
            return value1;
        }
        else if (is_zero(value2) && (float_to_bits(value1) >> 31) != 1 ){
            return value1;
        }
        else if (is_zero(value2) && (float_to_bits(value1) >> 31) == 1 ){
            return value2;
        }
        else if (is_positive_inf(value1)){
            return value1;
        }
        else if (is_negative_inf(value1)){
            return value2;
        }
    }
    else{
        if(is_nan(value1)){
            return value2;
        }
        else if(is_nan(value2)){
            return value1;
        }
        if (is_subnormal(value1)){
            return value2;
        }
        else if (is_subnormal(value2)){
            return value1;
        }
        if (is_positive_inf(value2)) {
            return value2;
        }
        else if (is_zero(value2) && !is_positive_inf(value1)) {
            return value2;
        }
    }

    return value1;
}

inline double max(double const value1, double const value2){
    if(is_normal(value1) && is_normal(value2)){
        if(is_signed(value1) || value2){
            if (is_signed(value1)){
                return value2;
            }else {
                return value1;
            }
        }else {
            if ((float_to_bits(value1) & 9223372036854775807) < (float_to_bits(value2) & 9223372036854775807)){  // 9223372036854775807 = 0111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 in binary
                return value2;
            }
            else {
                return value1;
            }
        }
    }
    else if(is_normal(value1) ^ is_normal(value2)){
        if (is_nan(value1)){
            return value2;
        }
        else if (is_zero(value1) && (float_to_bits(value2) >> 63) != 1 ){
            return value2;
        }
        else if (is_zero(value1) && (float_to_bits(value2) >> 63) == 1 ){
            return value1;
        }
        else if (is_zero(value2) && (float_to_bits(value1) >> 63) != 1 ){
            return value1;
        }
        else if (is_zero(value2) && (float_to_bits(value1) >> 63) == 1 ){
            return value2;
        }
        else if (is_positive_inf(value1)){
            return value1;
        }
        else if (is_negative_inf(value1)){
            return value2;
        }
    }
    else{
        if(is_nan(value1)){
            return value2;
        }
        else if(is_nan(value2)){
            return value1;
        }
        if (is_subnormal(value1)){
            return value2;
        }
        else if (is_subnormal(value2)){
            return value1;
        }
        if (is_positive_inf(value2)) {
            return value2;
        }
        else if (is_zero(value2) && !is_positive_inf(value1)) {
            return value2;
        }
    }

    return value1;
}

template<typename T>
float clump(T const value, T const min_v, T const max_v){
    return max(min(value, max_v), min_v);
}

template<typename T>
bool are_equal_with_percision(T const value1, T const value2, T const percission){
    return abss(value1 - value2) < percission;
}

template<typename T>
bool are_equal(T const value1, T const value2){
    T percission;
    if(sizeof(value1) == 4){
       percission = 1e-7;
    }
    else{
        percission = 1e-16;
    }
    return abss(value1 - value2) < percission;
}

template<typename T>
bool less_with_percision(T const value1, T const value2, T const percission){
    return (value2 + percission - value1) > 0;
}

template<typename T>
bool less(T const value1, T const value2){
    T percission;
    if(sizeof(value1) == 4){
       percission = 1e-7;
    }
    else{
        percission = 1e-16;
    }
    return (value2 + percission - value1) > 0;
}

template<typename T>
bool greater_with_percision(T const value1, T const value2, T const percission){
    return (value1 + percission - value2)  > 0;
}

template<typename T>
bool greater(T const value1, T const value2){
    T percission;
    if(sizeof(value1) == 4){
       percission = 1e-7;
    }
    else{
        percission = 1e-16;
    }
    return (value1 + percission - value2)  > 0;
}

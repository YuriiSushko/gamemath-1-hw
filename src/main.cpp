#include "float_functions.h"

int main(){
    double inf_value = 1.0e-45f;

    // Shift right to create a subnormal value
    for (int i = 0; i < 712; ++i) {
        inf_value /= 2.45;
    }

    float const value = 2.0e-10f;
    uint64_t bit_value_inf = float_to_bits(inf_value);
    uint32_t bit_value = float_to_bits(value);
    print_number_info(bit_value);
    
    print_number_info(bit_value_inf);
    double float_from_bits_inf = bits_to_float(bit_value_inf);
    print_number_info(float_from_bits_inf);

    std::cout << is_zero(inf_value) << std::endl;
    return 0;
}
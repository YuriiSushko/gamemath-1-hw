#include <iostream>
#include <xmmintrin.h>
#include <smmintrin.h>

struct vector4
{
    public:
        vector4(float x, float y, float z)
        {
            m_data = _mm_set_ps(0.0f, z, y, x);
        }

        vector4(float x, float y, float z, float w)
        {
            m_data = _mm_set_ps(w, z, y, x);
        }

    public:
        float x() const { 
            float values[4];
            _mm_storeu_ps(values, m_data);
            return values[0]; 
        }
        float y() const { 
            float values[4];
            _mm_storeu_ps(values, m_data);
            return values[1]; 
        }
        float z() const { 
            float values[4];
            _mm_storeu_ps(values, m_data);
            return values[2]; 
        }
        float w() const { 
            float values[4];
            _mm_storeu_ps(values, m_data);
            return values[3];  
        }

        vector4& add(const vector4 &other) {
            m_data = _mm_add_ps(m_data, other.m_data);
            return *this;
        }

        vector4& add(float x, float y, float z) {
            __m128 addVec = _mm_set_ps(0.0f, z, y, x);
            m_data = _mm_add_ps(m_data, addVec);
            return *this;
        }
    
        vector4& sub(const vector4 &other) {
            m_data = _mm_sub_ps(m_data, other.m_data);
            return *this;
        }
    
        vector4& sub(float x, float y, float z) {
            __m128 subVec = _mm_set_ps(0.0f, z, y, x);
            m_data = _mm_sub_ps(m_data, subVec);
            return *this;
        }

        vector4& mul(float scale) {
            __m128 scaleVec = _mm_set_ps(1.0f, scale, scale, scale);
            m_data = _mm_mul_ps(m_data, scaleVec);
            return *this;
        }
    
        vector4& mul(float scale, float w_scale) {
            __m128 scaleVec = _mm_set_ps(w_scale, scale, scale, scale);
            m_data = _mm_mul_ps(m_data, scaleVec);
            return *this;
        }

        vector4& div(float scale) {
            __m128 scaleVec = _mm_set_ps(1.0f, scale, scale, scale);
            m_data = _mm_div_ps(m_data, scaleVec);
            return *this;
        }

        vector4& div(float scale, float w_scale) {
            __m128 scaleVec = _mm_set_ps(w_scale, scale, scale, scale);
            m_data = _mm_div_ps(m_data, scaleVec);
            return *this;
        }

        vector4& dot(const vector4 &other){
            m_data = _mm_dp_ps(m_data, other.m_data, 0xF1);
            return *this;
        }
        vector4& dot(float x, float y, float z){
            __m128 dotVec = _mm_set_ps(0.0f, z, y, x);
            m_data = _mm_dp_ps(m_data, dotVec, 0xF1);
            return *this;
        }

        float magnitude() const{
            __m128 sqrMagnitude = _mm_dp_ps(m_data, m_data, 0xF1);
            __m128 magnitude = _mm_sqrt_ps(sqrMagnitude);
            float values[4];
            _mm_storeu_ps(values, magnitude);
            return values[0]; 
        }

        float magnitude_square() const{
            __m128 sqrMagnitude = _mm_dp_ps(m_data, m_data, 0xF1);
            float values[4];
            _mm_storeu_ps(values, sqrMagnitude);
            return values[0]; 
        }

        vector4& normalize(){
            float mgn = magnitude();
            div(mgn);
            return *this;
        }

    private:
        __m128 m_data;
};

void print(vector4 v3){
    float x3, y3, z3, w3;

    x3 = v3.x();
    y3 = v3.y();
    z3 = v3.z();
    w3 = v3.w();

    std::cout << "Vector: " << x3 << ", " << y3 << ", " << z3 << ", " << w3 << "\n";
}

int main() {
    vector4 v3_1(1.0f, 2.0f, 3.0f);
    vector4 v3_2(1.0f, 2.0f, 3.0f);
    vector4 v4(1.0f, 2.0f, 3.0f, 4.0f);

    print(v3_1);
    print(v4);

    v3_1.add(v3_2);
    print(v3_1);

    v3_1.div(3);
    print(v3_1);

    float res = v3_1.magnitude();
    std::cout<<res<<"\n";

    float res_sqr = v3_1.magnitude_square();
    std::cout<<res_sqr<<"\n";

    v3_1.dot(v3_1);
    print(v3_1);

    v3_2.normalize();
    print(v3_2);
    return 0;
}

#pragma once

#include <iostream>

#include "vector2.h"

struct Matrix44 {
    float mat[4][4];

    inline Matrix44() {
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                this->mat[i][j] = 0;
            }
        }
    }

    inline Matrix44(float m00, float m01, float m02, float m03,
                    float m10, float m11, float m12, float m13,
                    float m20, float m21, float m22, float m23,
                    float m30, float m31, float m32, float m33) {
        
        this->mat[0][0] = m00; this->mat[0][1] = m01; this->mat[0][2] = m02; this->mat[0][3] = m03;
        this->mat[1][0] = m10; this->mat[1][1] = m11; this->mat[1][2] = m12; this->mat[1][3] = m13;
        this->mat[2][0] = m20; this->mat[2][1] = m21; this->mat[2][2] = m22; this->mat[2][3] = m23;
        this->mat[3][0] = m30; this->mat[3][1] = m31; this->mat[3][2] = m32; this->mat[3][3] = m33;
    }

    inline void printMat(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                std::cout << this->mat[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

struct Matrix14 {
    float mat[1][4];

    inline Matrix14(){
        for(int i = 0; i < 1; i++){
            for(int j = 0; j < 4; j++){
                this->mat[i][j] = 0;
            }
        }
    }

    inline Matrix14(float t) {
        float tt = t*t;
        float ttt = tt*t;

        this->mat[0][0] = ttt; this->mat[0][1] = tt; this->mat[0][2] = t; this->mat[0][3] = 1;
    }

    inline void printMat(){
        for(int i = 0; i < 1; i++){
            for(int j = 0; j < 4; j++){
                std::cout << this->mat[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

struct Matrix42 {
    float mat[4][2];

    inline Matrix42(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 2; j++){
                this->mat[i][j] = 0;
            }
        }
    }

    inline Matrix42(Vector2& p0, Vector2& p1, Vector2& p2, Vector2& p3){
        this->mat[0][0] = p0.m_x; this->mat[0][1] = p0.m_y;
        this->mat[1][0] = p1.m_x; this->mat[1][1] = p1.m_y;
        this->mat[2][0] = p2.m_x; this->mat[2][1] = p2.m_y;
        this->mat[3][0] = p3.m_x; this->mat[3][1] = p3.m_y; 
    }

    inline void printMat(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 2; j++){
                std::cout << this->mat[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

static float[][] multMat14Mat44(const float mat14[1][4], const float mat44[4][4]){
    float res[1][4];
    
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < 4; j++){
            res[i][j] = 0;
            
            for(int k = 0; k < 4; k++){
                res[i][j] += mat14[i][k] * mat44[k][j];
            }
        }
    }
    return res;
}   

namespace matrix{
    static float[][] multMat14Mat42(const float mat14[1][4], const float mat41[4][2]){
        float res[1][2];
        
        for(int i = 0; i < 1; i++){
            for(int j = 0; j < 2; j++){
                res[i][j] = 0;
                
                for(int k = 0; k < 2; k++){
                    res[i][j] += mat14[i][k] * mat44[k][j];
                }
            }
        }
        return res;
    }
}
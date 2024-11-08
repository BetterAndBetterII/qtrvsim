//
// Created by Gary on 24-11-4.
//

#ifndef QTRVSIM_VECTOR_H
#define QTRVSIM_VECTOR_H

#include "vector_register.h"
#include "register_value.h"
#include "execute/vector_op.h"
#include <cstdint>
#include <vector>

namespace machine {


void vector_operate(
    VectorOp op,
    VectorRegister &vd,
    const VectorRegister *vs2 = nullptr,
    const VectorRegister *vs1 = nullptr,
    RegisterValue rs1 = RegisterValue(0),
    int32_t imm = 0,
    uint8_t *memory = nullptr,
    uint32_t addr = 0);

RegisterValue vector_operate(
    VectorOp op,
    const VectorRegister *vs2 = nullptr,
    const VectorRegister *vs1 = nullptr,
    RegisterValue rs1 = RegisterValue(0),
    RegisterValue imm = RegisterValue(0));

VectorRegister vector_operate_vector(
    VectorOp op,
    const VectorRegister *vs2,
    const VectorRegister *vs1,
    RegisterValue rs1,
    RegisterValue imm);

// 向量操作函数声明
RegisterValue vector_set_vl(RegisterValue rs1, RegisterValue rs2);

void vector_add_vv(VectorRegister &vd, 
                  const VectorRegister &vs2,
                  const VectorRegister &vs1);

VectorRegister vector_add_vv(const VectorRegister &vs2,
                            const VectorRegister &vs1);

void vector_add_vx(VectorRegister &vd,
                  const VectorRegister &vs2, 
                  RegisterValue rs1);

VectorRegister vector_add_vx(const VectorRegister &vs2,
                            RegisterValue rs1);

void vector_add_vi(VectorRegister &vd,
                  const VectorRegister &vs2,
                  int32_t imm);

VectorRegister vector_add_vi(const VectorRegister &vs2,
                             RegisterValue imm);

void vector_mul_vv(VectorRegister &vd,
                  const VectorRegister &vs2,
                  const VectorRegister &vs1);

RegisterValue vector_mul_vv(const VectorRegister &vs2,
                            const VectorRegister &vs1);

void vector_load(VectorRegister &vd,
                const uint8_t *memory,
                uint32_t base_addr);

void vector_store(const VectorRegister &vs3,
                 uint8_t *memory,
                 uint32_t base_addr);

// 获取当前向量长度和类型
uint32_t get_vector_length();
uint32_t get_vector_type();

} // namespace machine

#endif // QTRVSIM_VECTOR_H

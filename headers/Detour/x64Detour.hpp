//
// Created by steve on 7/4/17.
//

#ifndef POLYHOOK_2_X64DETOUR_HPP
#define POLYHOOK_2_X64DETOUR_HPP

#include <sstream>

#include "headers/Detour/ADetour.hpp"
#include "headers/Enums.hpp"
#include "headers/Instruction.hpp"

namespace PLH {

class x64Detour : public Detour
{
public:
	x64Detour(const uint64_t fnAddress, const uint64_t fnCallback, PLH::ADisassembler& dis);

	x64Detour(const char* fnAddress, const char* fnCallback, PLH::ADisassembler& dis);

	virtual bool hook() override;

	virtual bool unHook() override;

    Mode getArchType() const;

    insts_t makeMinimumJump(const uint64_t address, const uint64_t destination) const;

    insts_t makePreferredJump(const uint64_t address, const uint64_t destination) const;

	uint8_t* makeTrampolineNear(const uint64_t hint, const uint64_t size) const;
private:
 
};
}
#endif //POLYHOOK_2_X64DETOUR_HPP
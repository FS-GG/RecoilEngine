/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ExternalAI/Interface/SSkirmishAICallback.h"
#include "Sim/Units/CommandAI/CommandQueue.h"

#include <catch_amalgamated.hpp>

#include <cstddef>
#include <type_traits>

namespace {

using CountByType = int (*)(int, int, int);
using IntGetterByType = int (*)(int, int, int, int);
using OptionsGetterByType = short (*)(int, int, int, int);
using ParamsGetterByType = int (*)(int, int, int, int, float*, int);

static_assert(std::is_same_v<decltype(SSkirmishAICallback::Unit_getCurrentCommandsByType), CountByType>);
static_assert(std::is_same_v<decltype(SSkirmishAICallback::Unit_CurrentCommandByType_getType), IntGetterByType>);
static_assert(std::is_same_v<decltype(SSkirmishAICallback::Unit_CurrentCommandByType_getId), IntGetterByType>);
static_assert(std::is_same_v<decltype(SSkirmishAICallback::Unit_CurrentCommandByType_getOptions), OptionsGetterByType>);
static_assert(std::is_same_v<decltype(SSkirmishAICallback::Unit_CurrentCommandByType_getTag), IntGetterByType>);
static_assert(std::is_same_v<decltype(SSkirmishAICallback::Unit_CurrentCommandByType_getTimeOut), IntGetterByType>);
static_assert(std::is_same_v<decltype(SSkirmishAICallback::Unit_CurrentCommandByType_getParams), ParamsGetterByType>);

static_assert(CCommandQueue::CommandQueueType == 0);
static_assert(CCommandQueue::NewUnitQueueType == 1);
static_assert(CCommandQueue::BuildQueueType == 2);

} // namespace

TEST_CASE("Rally queue callbacks remain an append-only ABI extension")
{
	CHECK(offsetof(SSkirmishAICallback, Unit_getCurrentCommandsByType) >
	      offsetof(SSkirmishAICallback, Debug_GraphDrawer_isEnabled));
	CHECK(offsetof(SSkirmishAICallback, Unit_CurrentCommandByType_getType) >
	      offsetof(SSkirmishAICallback, Unit_getCurrentCommandsByType));
	CHECK(offsetof(SSkirmishAICallback, Unit_CurrentCommandByType_getParams) >
	      offsetof(SSkirmishAICallback, Unit_CurrentCommandByType_getTimeOut));
}

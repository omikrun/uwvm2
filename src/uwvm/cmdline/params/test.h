﻿/********************************************************
 * Ultimate WebAssembly Virtual Machine (Version 2)     *
 * Copyright (c) 2025 UlteSoft. All rights reserved.    *
 * Licensed under the APL-2 License (see LICENSE file). *
 ********************************************************/

/**
 * @author      MacroModel
 * @version     2.0.0
 * @date        2025-04-07
 * @copyright   APL-2 License
 */

/****************************************
 *  _   _ __        ____     __ __  __  *
 * | | | |\ \      / /\ \   / /|  \/  | *
 * | | | | \ \ /\ / /  \ \ / / | |\/| | *
 * | |_| |  \ V  V /    \ V /  | |  | | *
 *  \___/    \_/\_/      \_/   |_|  |_| *
 *                                      *
 ****************************************/

#pragma once

#ifdef _DEBUG

# ifdef UWVM_MODULE
import fast_io;
import ulte.utils.cmdline;
# else
// std
#  include <memory>
// macro
#  include <utils/macro/push_macros.h>
#  include <uwvm/utils/ansies/uwvm_color_push_macro.h>
// import
#  include <fast_io.h>
#  include <fast_io_dsal/string_view.h>
#  include <utils/cmdline/impl.h>
# endif

# ifndef UWVM_MODULE_EXPORT
#  define UWVM_MODULE_EXPORT
# endif

UWVM_MODULE_EXPORT namespace ulte::uwvm::cmdline::paras
{
    namespace details
    {
        inline bool test_is_exist{};
        extern "C++" ::ulte::utils::cmdline::parameter_return_type test_callback(::ulte::utils::cmdline::parameter_parsing_results*,
                                                                           ::ulte::utils::cmdline::parameter_parsing_results*,
                                                                           ::ulte::utils::cmdline::parameter_parsing_results*) noexcept;

    }  // namespace details

    inline constexpr ::ulte::utils::cmdline::parameter test{.name{u8"--test"},
                                                      .describe{u8"Debug Test."},
                                                      .handle{::std::addressof(details::test_callback)},
                                                      .is_exist{::std::addressof(details::test_is_exist)}};
}  // namespace ulte::uwvm::cmdline::paras

# ifndef UWVM_MODULE
#  include <uwvm/utils/ansies/uwvm_color_pop_macro.h>
#  include <utils/macro/pop_macros.h>
# endif
#endif

/**
    ─────────────────────────────── ⋆⋅☆⋅⋆ ───────────────────────────────
                     ░░░░░██╗░█████╗░██╗░░░██╗████████╗
                     ░░░░░██║██╔══██╗██║░░░██║╚══██╔══╝
                     ░░░░░██║███████║██║░░░██║░░░██║░░░
                     ██╗░░██║██╔══██║██║░░░██║░░░██║░░░
                     ╚█████╔╝██║░░██║╚██████╔╝░░░██║░░░
                     ░╚════╝░╚═╝░░╚═╝░╚═════╝░░░░╚═╝░░░
                       JUCE Augmented Utility  Toolbox
    ─────────────────────────────── ⋆⋅☆⋅⋆ ───────────────────────────────
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any internal version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <https://www.gnu.org/licenses/>.

    Copyright (c) 2022 ElandaSunshine
    ===============================================================

    @author Elanda
    @file   jaut_Define.h
    @date   02, March 2020

    ===============================================================
 */

#pragma once

/** JAUT exporter */
#undef JAUT_API

#if JUCE_MSVC
    #ifdef JAUT_DLL_BUILD
        #define JAUT_API __declspec(dllexport)
        #pragma warning (disable: 4251)
    #elif defined (JAUT_DLL)
        #define JAUT_API __declspec(dllimport)
        #pragma warning(disable: 4251)
    #endif
    #ifdef __INTEL_COMPILER
        #pragma warning(disable: 1125)
    #endif
#elif defined(JAUT_DLL) || defined(JAUT_DLL_BUILD)
    #define JAUT_API __attribute__((visibility("default")))
#endif

#ifndef JAUT_API
    #define JAUT_API
#endif

/** Fancy helper macro for debugging */
#ifdef JUCE_DEBUG
    #define JAUT_DEBUGGING(x) x
    #define JAUT_NDEBUGGING(x)
    #define JAUT_DEBUGGING_OR(x, y) x
#else
    #define JAUT_DEBUGGING(x)
    #define JAUT_NDEBUGGING(x) x
    #define JAUT_DEBUGGING_OR(x, y) y
#endif

#define JAUT_NODISCARD [[nodiscard]]

/** Config: JAUT_CORE_NOTNULL_HANDLE_NULLPTRS
    This determines how jaut::NonNull should handle nullptrs if they were bound prior to assigning the wrapper.
    
    <table>
        <caption>There is three possible approaches</caption>
        <tr>
            <th>Key</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>Throwing: 0 (default)</td>
            <td>Throws if a nullptr was encountered</td>
        </tr>
        <tr>
            <td>Terminating: 1</td>
            <td>Terminates if a nullptr was encountered</td>
        </tr>
        <tr>
            <td>Ignoring: 2</td>
            <td>Ignores the nullptr and continues as though nothing has happened</td>
        </tr>
    </table>
 */
#ifndef JAUT_CORE_NOTNULL_HANDLE_NULLPTRS
    #define JAUT_CORE_NOTNULL_HANDLE_NULLPTRS 0
#endif
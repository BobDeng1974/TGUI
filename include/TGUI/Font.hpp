/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012-2016 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_FONT_HPP
#define TGUI_FONT_HPP

#include <TGUI/Global.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API Font
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor which will set the font to nullptr
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Font();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructor which will explicitly set the font to nullptr
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Font(std::nullptr_t);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructor to create the font from a string (filename by default)
        ///
        /// @param id  String to pass to the Deserializer class to load the font
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Font(const std::string& id);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructor to create the font from a string (filename by default)
        ///
        /// @param id  String to pass to the Deserializer class to load the font
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Font(const char* id);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructor to share the font directly
        ///
        /// @param font  Font to share
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Font(std::shared_ptr<sf::Font> font);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructor to set a copy of your font
        ///
        /// @param font  Font to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Font(const sf::Font& font);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Gets the underlying SFML font
        ///
        /// @return Font stored in this object
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<sf::Font> getFont() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        std::shared_ptr<sf::Font> m_font;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_TEXTURE_HPP

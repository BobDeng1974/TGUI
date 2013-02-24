/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_GRID_HPP
#define TGUI_GRID_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API Grid : public GroupObject
    {
      public:

        typedef SharedObjectPtr<Grid> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief The layout of the object.
        ///
        /// Where in the cell is the object located?
        /// The object is centered by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct Layout
        {
            enum Layouts
            {
                /// Draw the object in the upper left corner of the cell
                UpperLeft,

                /// Draw the object at the upper side of the cell (horizontally centered)
                Up,

                /// Draw the object in the upper right corner of the cell
                UpperRight,

                /// Draw the object at the right side of the cell (vertically centered)
                Right,

                /// Draw the object in the bottom right corner of the cell
                BottomRight,

                /// Draw the object at the bottom of the cell (horizontally centered)
                Bottom,

                /// Draw the object in the bottom left corner of the cell
                BottomLeft,

                /// Draw the object at the left side of the cell (vertically centered)
                Left,

                /// Center the object in the cell
                Center
            };
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Grid();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Grid(const Grid& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~Grid();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Grid& operator= (const Grid& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the object by calling the copy constructor.
        // This function calls new and if you use this function then you are responsible for calling delete.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Grid* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the grid.
        ///
        /// \return Size of the grid
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes a single object that was added to the group.
        ///
        /// \param object  Pointer to the object to remove
        ///
        /// \see remove(sf::String)
        ///
        /// Usage example:
        /// \code
        /// tgui::Picture::Ptr pic(grid, "picName");
        /// tgui::Picture::Ptr pic2(grid, "picName2");
        /// grid.remove(pic);
        /// grid.remove(grid.get("picName2"));
        /// \endcode
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void remove(const Object::Ptr& object);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes a single object that was added to the group.
        ///
        /// \param object  Pointer to the object to remove
        ///
        /// This function is provided for internal use.
        /// The other remove function will probably be easier to use, but in the end they do exactly the same.
        ///
        /// \see remove(Object::Ptr)
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void remove(Object* object);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes all objects that were added to the group.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void removeAllObjects();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Add a new object to the next column.
        ///
        /// \param object   Pointer to a fully created object that will be added to the grid.
        /// \param borders  Distance from the grid square to the object (left, top, right, bottom).
        /// \param layout   Where the object is located in the square.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void addToRow(const Object::Ptr& object, const Vector4u& borders = Vector4u(0, 0, 0, 0), Layout::Layouts layout = Layout::Center);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Adds a new row to the grid.
        ///
        /// \param rowHeight  The height of the row when it stays empty, or the minimum height when objects are added to the row.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void addRow(unsigned int rowHeight = 0);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Updates the position and size of the object.
        ///
        /// After an object has been added to the grid, you will have to call this function when you change the size of the object.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void updateObjects();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the layout of a given object.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void changeObjectLayout(const Object::Ptr& object, Layout::Layouts layout = Layout::Center);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Used to communicate with EventManager.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnObject(float x, float y);
        virtual void objectFocused();
        virtual void objectUnfocused();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Reposition all the objects.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void updatePositionsOfAllObjects();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Because this class is derived from sf::Drawable, you can just call the draw function from your sf::RenderTarget.
        // This function will be called and it will draw the grid object on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        enum GridCallbacks
        {
            AllGridCallbacks = ObjectCallbacksCount - 1,
            GridCallbacksCount = ObjectCallbacksCount
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        std::vector< std::vector<Object::Ptr> >     m_GridObjects;
        std::vector< std::vector<Vector4u> >        m_ObjBorders;
        std::vector< std::vector<Layout::Layouts> > m_ObjLayout;

        std::vector<unsigned int> m_RowHeight;
        std::vector<unsigned int> m_ColumnWidth;

        Vector2f  m_Size;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_GRID_HPP

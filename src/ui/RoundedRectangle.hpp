////////////////////////////////////////////////////////////
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef ROUNDEDRECTANGLESHAPE_HPP
#define ROUNDEDRECTANGLESHAPE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Specialized shape representing a rectangle
/// with rounded corners
////////////////////////////////////////////////////////////
class RoundedRectangleShape : public sf::Shape
{
    public:
        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// \param size Size of the rectangle
        /// \param radius Radius for each rounded corner
        /// \param pointCount Number of points of each corner
        ///
        ////////////////////////////////////////////////////////////
        RoundedRectangleShape(const Vector2f& size, float radius, unsigned int cornerPointCount)
        {
            mySize = size;
            myRadius = radius;
            myCornerPointCount = cornerPointCount;
            update();
        }

        ////////////////////////////////////////////////////////////
        void setSize(const Vector2f& size)
        {
            mySize = size;
            update();
        }

        ////////////////////////////////////////////////////////////
        const Vector2f& getSize() const
        {
            return mySize;
        }

        ////////////////////////////////////////////////////////////
        void setCornersRadius(float radius)
        {
            myRadius = radius;
            update();
        }

        ////////////////////////////////////////////////////////////
        const float getCornersRadius() const
        {
            return myRadius;
        }

        ////////////////////////////////////////////////////////////
        void setCornerPointCount(unsigned int count)
        {
            myCornerPointCount = count;
            update();
        }

        ////////////////////////////////////////////////////////////
        std::size_t getPointCount() const
        {
            return myCornerPointCount*4;
        }

        ////////////////////////////////////////////////////////////
        sf::Vector2f getPoint(std::size_t index) const
        {
            if(index >= myCornerPointCount*4)
                return sf::Vector2f(0,0);

            float deltaAngle = 90.0f/(myCornerPointCount-1);
            sf::Vector2f center;
            unsigned int centerIndex = index/myCornerPointCount;
            unsigned int offset = 0;
            static const float pi = 3.141592654f;

            switch(centerIndex)
            {
                case 0: center.x = mySize.x - myRadius; center.y = myRadius; break;
                case 1: center.x = myRadius; center.y = myRadius; break;
                case 2: center.x = myRadius; center.y = mySize.y - myRadius; break;
                case 3: center.x = mySize.x - myRadius; center.y = mySize.y - myRadius; break;
            }

            return sf::Vector2f(myRadius*cos(deltaAngle*(index-centerIndex)*pi/180)+center.x,
                                -myRadius*sin(deltaAngle*(index-centerIndex)*pi/180)+center.y);
        }
    private:
         ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        Vector2f mySize;
        float myRadius;
        unsigned int myCornerPointCount;
};
}
#endif // ROUNDEDRECTANGLESHAPE_HPP

////////////////////////////////////////////////////////////
/// \class sf::RoundedRectangleShape
/// \ingroup graphics
///
/// This class inherits all the functions of sf::Transformable
/// (position, rotation, scale, bounds, ...) as well as the
/// functions of sf::Shape (outline, color, texture, ...).
///
/// Usage example:
/// \code
/// sf::RoundedRectangleShape roundedRectangle;
/// rectangle.setSize(sf::Vector2f(100, 50));
/// rectangle.setCornersRadius(5);
/// rectangle.setOutlineThickness(5);
/// rectangle.setPosition(10, 20);
/// ...
/// window.draw(rectangle);
/// \endcode
///
/// \see sf::Shape, sf::CircleShape, sf::ConvexShape
///
////////////////////////////////////////////////////////////

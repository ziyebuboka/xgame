#ifndef     __FTPoint__
#define     __FTPoint__

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include "FT.h"

namespace xs{


/**
 * FTPoint class is a basic 3 dimensional point or vector.
 */
class FTPoint
{
    public:
        /**
         * Default constructor. Point is set to zero.
         */
        FTPoint()
        {
            values[0] = 0;
            values[1] = 0;
            values[2] = 0;
        }
        
        /**
         * Constructor.
         *
         * @param x First component
         * @param y Second component
         * @param z Third component
         */
        FTPoint( const FT_DOUBLE x, const FT_DOUBLE y, const FT_DOUBLE z)
        {
            values[0] = x;
            values[1] = y;
            values[2] = z;
        }
        
        /**
         * Constructor. This converts an FT_Vector to an FT_Point
         *
         * @param ft_vector A freetype vector
         */
        FTPoint( const FT_Vector& ft_vector)
        {
            values[0] = ft_vector.x;
            values[1] = ft_vector.y;
            values[2] = 0;
        }
        
        /**
         * Operator += In Place Addition.
         *
         * @param point
         * @return this plus point.
         */
        FTPoint& operator += ( const FTPoint& point)
        {
            values[0] += point.values[0];
            values[1] += point.values[1];
            values[2] += point.values[2];

            return *this;
        }

        /**
         * Operator +
         *
         * @param point
         * @return this plus point.
         */
        FTPoint operator + ( const FTPoint& point)
        {
            FTPoint temp;
            temp.values[0] = values[0] + point.values[0];
            temp.values[1] = values[1] + point.values[1];
            temp.values[2] = values[2] + point.values[2];

            return temp;
        }
        
        
        /**
         * Operator *
         *
         * @param multiplier
         * @return <code>this</code> multiplied by <code>multiplier</code>.
         */
        FTPoint operator * ( double multiplier)
        {
            FTPoint temp;
            temp.values[0] = values[0] * multiplier;
            temp.values[1] = values[1] * multiplier;
            temp.values[2] = values[2] * multiplier;

            return temp;
        }
        
        
        /**
         * Operator *
         *
         * @param point
         * @param multiplier
         * @return <code>multiplier</code> multiplied by <code>point</code>.
         */
        friend FTPoint operator*( double multiplier, FTPoint& point);


        /**
         * Operator == Tests for eqaulity
         *
         * @param a
         * @param b
         * @return true if a & b are equal
         */
        friend bool operator == ( const FTPoint &a, const FTPoint &b);

        /**
         * Operator != Tests for non equality
         *
         * @param a
         * @param b
         * @return true if a & b are not equal
         */
        friend bool operator != ( const FTPoint &a, const FTPoint &b);
        
        
        /**
         * Cast to FT_DOUBLE*
         */
        operator const FT_DOUBLE*() const
        {
            return values;
        }
        

        /**
         * Setters
         */
        void  X( FT_DOUBLE x) { values[0] = x;};
        void  Y( FT_DOUBLE y) { values[1] = y;};
        void  Z( FT_DOUBLE z) { values[2] = z;};


        /**
         * Getters
         */
        FT_DOUBLE X() const { return values[0];};
        FT_DOUBLE Y() const { return values[1];};
        FT_DOUBLE Z() const { return values[2];};
        
    private:
        /**
         * The point data
         */
        FT_DOUBLE values[3];
};


}
#endif  //  __FTPoint__

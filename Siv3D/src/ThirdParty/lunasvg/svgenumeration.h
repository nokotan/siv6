#ifndef SVGENUMERATION_H
#define SVGENUMERATION_H

#include "svgproperty.h"

#include <vector>

namespace lunasvg {

enum Display
{
    DisplayInline,
    DisplayBlock,
    DisplayNone,
};

enum Visibility
{
    VisibilityVisible,
    VisibilityHidden,
    VisibilityCollaspe
};

enum Overflow
{
    OverflowVisible,
    OverflowHidden,
    OverflowScroll,
    OverflowAuto
};

enum LineCap
{
    LineCapButt,
    LineCapRound,
    LineCapSquare,
};

enum LineJoin
{
    LineJoinMiter,
    LineJoinRound,
    LineJoinBevel
};

enum WindRule
{
    WindRuleNonZero,
    WindRuleEvenOdd
};

enum UnitType
{
    UnitTypeUserSpaceOnUse,
    UnitTypeObjectBoundingBox
};

enum SpreadMethod
{
    SpreadMethodPad,
    SpreadMethodReflect,
    SpreadMethodRepeat
};

typedef std::pair<unsigned short, std::string> EnumEntry;
typedef std::vector<EnumEntry> EnumEntryList;

template<typename Enum> const EnumEntryList& getEnumEntryList();
template<> const EnumEntryList& getEnumEntryList<Display>();
template<> const EnumEntryList& getEnumEntryList<Visibility>();
template<> const EnumEntryList& getEnumEntryList<Overflow>();
template<> const EnumEntryList& getEnumEntryList<LineCap>();
template<> const EnumEntryList& getEnumEntryList<LineJoin>();
template<> const EnumEntryList& getEnumEntryList<WindRule>();
template<> const EnumEntryList& getEnumEntryList<SpreadMethod>();
template<> const EnumEntryList& getEnumEntryList<UnitType>();

class SVGEnumerationBase : public SVGProperty
{
public:
    void setValue(unsigned short value) { m_value = value; }
    unsigned short value() const { return m_value; }

    void setValueAsString(const std::string& value);
    std::string valueAsString() const;
    static PropertyType classType() { return PropertyTypeEnumeration; }

protected:
    SVGEnumerationBase(const EnumEntryList& entries) :
        SVGProperty(PropertyTypeEnumeration),
        m_value(0),
        m_entries(entries)
    {}

protected:
    unsigned short m_value;
    const EnumEntryList& m_entries;
};

template<typename T>
class SVGEnumeration : public SVGEnumerationBase
{
public:
    SVGEnumeration() :
        SVGEnumerationBase(getEnumEntryList<T>())
    {}

    T enumValue() const
    {
        return static_cast<T>(m_value);
    }

    void setEnumValue(T value)
    {
        m_value = value;
    }

    SVGProperty* clone() const
    {
        SVGEnumeration<T>* property = new SVGEnumeration<T>();
        property->m_value = m_value;

        return property;
    }
};

template<typename T>
class DOMSVGEnumeration : public DOMSVGProperty<SVGEnumeration<T>>
{
public:
    DOMSVGEnumeration(DOMPropertyID propertyId) :
        DOMSVGProperty<SVGEnumeration<T>>(propertyId)
    {}
};

} // namespace lunasvg

#endif // SVGENUMERATION_H

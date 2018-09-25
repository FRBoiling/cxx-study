//
// Created by boil on 18-9-20.
//

#ifndef BOIL_COPYABLE_H
#define BOIL_COPYABLE_H
namespace boil
{

/// A tag class emphasises the objects are copyable.
/// The empty base class optimization applies.
/// Any derived class of copyable should be a value type.
    class copyable
    {
    };

};

#endif //BOIL_COPYABLE_H

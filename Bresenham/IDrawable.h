#pragma once


// Drawable½Ó¿Ú
class IDrawable
{
public:
    IDrawable();
    virtual ~IDrawable();
    virtual void init() = 0;
    virtual void draw() = 0;
};


enum Color
{
    BLUE = 0,
    RED = 1,
    GREEN = 2
};

std::string toString(const Color& color)
{
    switch (color)
    {
    case Color::GREEN:
        return "Green";
        break;
    case Color::RED:
        return "Red";
        break;
    case Color::BLUE:   
        return "Blue";
        break;
    default:
        return "Not a Color";
    }
}

Color toEnum(const std::string& color)
{
    std::map<std::string, Color> Colors;
    Colors.insert({"Blue", Color::BLUE});
    Colors.insert({"Red", Color::RED});
    Colors.insert({"Green", Color::GREEN});

    auto it = Colors.find(color);

    return it -> second;
}
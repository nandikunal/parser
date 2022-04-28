#pragma once

#include <vector>
#include <memory>

namespace util
{
    class IOutput;

    /*!
    * This class declares Output Types
    */
    enum class OutputType
    {
        CONSOLE = 0,
        TEXT = 1,
        XML = 2,
        CONSOLE_TEXT = 3,
        CONSOLE_XML = 4,
        TEXT_XML = 5,
        ALL = 6
    };

    /*!
    * Factory class to create Output Types
    */
    class OutputFactory final
    {
    public:
        /*!
        * Constructor
        */
        OutputFactory() = default;

        /*!
        * Destructor
        */
        ~OutputFactory() = default;

        /*!
        * Intantiate Output Types
        * @param util::OutputType
        * @return list of Instances of OuputTypes
        */
        std::vector<std::shared_ptr<IOutput>> createOutput(const util::OutputType type);

    private:
        std::vector<std::shared_ptr<IOutput>> mOutputList{};
    };
} // namespace util

//
// Created by Amit and Tal on 18/01/2023.
//
 #include <exception>


 class DeckFileNotFound : public std::exception
 {
    public:
   const char* what() const noexcept override
   {
       return EXCEPTION_MSG;
   }
   
   private:
   static constexpr const char*  EXCEPTION_MSG = "Deck File Error: File not found";

 };

 class DeckFileFormatError : public std::exception
 {
    public:
    DeckFileFormatError(int line)  
    {
        m_exceptionMsg += std::to_string(line);
    }
    
   const char* what() const noexcept override
   { 
       return m_exceptionMsg.c_str();
   }
   
   private:
   std::string  m_exceptionMsg = "Deck File Error: File format error in line ";
 };

class DeckFileInvalidSize : public std::exception
{
    public:
      const char* what() const noexcept override
   { 
       return SIZE_INVALID_MSG;
   }

   private:
   static constexpr const char* SIZE_INVALID_MSG = "Deck File Error: Deck size is invalid";

};
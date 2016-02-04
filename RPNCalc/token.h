#ifndef TOKEN_H
#define TOKEN_H

using namespace std;

enum TokenType { EOL, VALUE, OPAREN, CPAREN, EXCLUSIVEOR, MULT, DIV, PLUS, MINUS, 
	MOD, LT, GT, LTET, GTET, LS, RS, EQUALS, IFEQUAL, NOTEQUAL, AND, LOGICALAND, OR, LOGICALOR, NEGATION, COMPLIMENT, UNARYPLUS, UNARYMINUS, VAR_A, VAR_B, VAR_C  };

template <class NumericType>
class Token {
 public:
  Token( TokenType tt = EOL, const NumericType & nt = 0 ) 
    : theType( tt ), theValue( nt ) {
  }

  TokenType getType( ) const {
    return theType;
  }
  const NumericType &getValue( ) const {
    return theValue;
  }
  
 private:
	TokenType prevToken;
	TokenType   theType;
	NumericType theValue;
};

#endif
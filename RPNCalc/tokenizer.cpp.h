template <class NumericType>
bool Tokenizer<NumericType>::getChar( char &ch ) {
  char tmp;

  // skip blanks
  while ( in.get( tmp ) && tmp == ' ' );

  // read a char 
  if ( in.good( ) && tmp != '\n'&& tmp != '\0' ) {
    ch = tmp;
    return true; // if it is not a delimiter
  }
  else
    return false; // if it's a delimitter
}

template <class NumericType>
Token<NumericType> Tokenizer<NumericType>::getToken( ) {

  char ch;
  char c;
  NumericType theValue;
  TokenType prevToken = MULT;
  
  if ( getChar( ch ) == true ) {
    switch( ch ) {
    case '^': 
		prevToken = EXCLUSIVEOR;
		return EXCLUSIVEOR;
    case '/': 
		prevToken = DIV;
		return DIV;
    case '*': 
		prevToken = MULT;
		return MULT;
    case '(': 
		prevToken = OPAREN;
		return OPAREN;
    case ')': 
		prevToken = CPAREN;
		return CPAREN;
	case '!': 
		prevToken = NEGATION;
		return NEGATION;
	case '~': 
		prevToken = COMPLIMENT;
		return COMPLIMENT;

    case '+': 
		if(prevToken == OPAREN)
		{
			prevToken = UNARYPLUS;
			return UNARYPLUS;
		}
		else
		{
			prevToken = PLUS;
			return PLUS;
		}

    case '-': 
		if(prevToken == OPAREN)
		{
			prevToken = UNARYMINUS;
			return UNARYMINUS;
		}
		else
		{
			prevToken = MINUS;
			return MINUS;
		}
	case '%': 
		prevToken = MOD;
		return MOD;
	case 'a':
		prevToken = VAR_A;
		return Token<NumericType>( VAR_A, 0 ); 
    case 'b':
		prevToken = VAR_B;
		return Token<NumericType>( VAR_B, 0 ); 
    case 'c':
		prevToken = VAR_C;
		return Token<NumericType>( VAR_C, 0 ); 
	case '<': 
		getChar(c); 
		if(c == '<')
		{
			prevToken = LS;
			return LS;
		}
		else if(c == '=')
		{
			prevToken = LTET;
			return LTET;
		}
		else
		{

			in.putback(c);
			prevToken = LT;
			return LT;
		}
	case '>': 
		getChar(c);
		if(c == '>')
		{
			prevToken = RS;
			return RS;
		}
		else if(c == '=')
		{
			prevToken = GTET;
			return GTET;
		}
		else
		{
			in.putback(c);
			prevToken = GT;
			return GT;
		}
	case '|':
		getChar(c);
		if(c == '|')
		{
			prevToken = LOGICALOR;
			return LOGICALOR;
		}
		else
		{
			in.putback(c);
			prevToken = OR;
			return OR;
		}
	case '&':
		getChar(c);
		if(c == '&')
			return LOGICALAND;
		else
		{
			in.putback(c);
			return AND;
		}
    default:
      in.putback( ch );
      if ( !( in >> theValue ) ) {
	cerr << "Parse error" << endl;
	prevToken = EOL;
	return EOL;
      }
      return Token<NumericType>( VALUE, theValue );
    }
  }
  prevToken = EOL;
  return EOL;
}
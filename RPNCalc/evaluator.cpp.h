// Public routine that performs the evaluation. Examines the postfix machine
// to see if a single result is left and if so, return it; otherwise prints
// error.
template<class NumericType>
NumericType Evaluator<NumericType>::getValue( ) {

  Tokenizer<NumericType> tok( str );
  Token<NumericType> lastToken;
  
  do {
    lastToken = tok.getToken( );
    processToken( lastToken );
  } while ( lastToken.getType( ) != EOL );

  if ( postFixStack.empty( ) ) {
    cerr << "Missing operatnd!" << endl;
    return 0;
  }

  NumericType theResult = postFixStack.back( );
  postFixStack.pop_back( );
  postFixVarStack.pop_back();
  if ( !postFixStack.empty( ) )
    cerr << "Warning: missing operators!" << endl;
  
  return theResult;
}

// After token is read, use operator precedence parsing algorithm to process
// it; missing opening parentheses are detected here.
template<class NumericType>
void Evaluator<NumericType>::
processToken( const Token<NumericType> &lastToken ) {
  TokenType topOp;
  TokenType lastType = lastToken.getType( );

  switch( lastType ) {
  case VALUE:
    postFixStack.push_back( lastToken.getValue( ) );
    postFixVarStack.push_back( ' ' );
    return;
    
  case VAR_A:
    postFixStack.push_back( var_a );
    postFixVarStack.push_back( 'a' );
    return;

  case VAR_B:
    postFixStack.push_back( var_b );
    postFixVarStack.push_back( 'b' );
    return;
  case VAR_C:
	postFixStack.push_back( var_c );
    postFixVarStack.push_back( 'c' );
    return;

  case CPAREN:
    while( ( topOp = opStack.back( ) ) != OPAREN &&
	   topOp != EOL )
      binaryOp( topOp );
    if ( topOp == OPAREN )
      opStack.pop_back( ); // get rid of opening parethesis
    else
      cerr << "Missing open parenthesis" << endl;
    break;

  default: // general operator case
    while ( PREC_TABLE[ lastType ].inputSymbol <= 
	    PREC_TABLE[ topOp = opStack.back( ) ].topOfStack )
      binaryOp( topOp );

    if ( lastToken.getType( ) != EOL )
      opStack.push_back( lastType );

    break;
  }
}

// Process an operator by taking two items off the postfix stack, applying
// the operator, and pushing the result.
// Print error if missing closing parenthesis or division by 0.
template<class NumericType>
void Evaluator<NumericType>::binaryOp( TokenType topOp ) {
  if ( topOp == OPAREN ) {
    cerr << "Unbalanced parenthss" << endl;
    opStack.pop_back( );
    return;
  }
  NumericType rhs = getTop( );
  NumericType lhs = getTop( );

  if ( topOp == EXCLUSIVEOR )
  {
	postFixVarStack.push_back(' ');
    postFixStack.push_back( lhs ^ rhs );
  }
  else if ( topOp == PLUS )
  {
	postFixVarStack.push_back(' ');
    postFixStack.push_back( lhs + rhs );
  }
  else if ( topOp == MINUS )
  {
	postFixVarStack.push_back(' ');
    postFixStack.push_back( lhs - rhs );
  }
  else if ( topOp == UNARYMINUS )
  {
	postFixVarStack.push_back(' ');
   if(rhs > 0)
		postFixStack.push_back( rhs * -1 );
	else
		postFixStack.push_back( rhs );
  }
  else if ( topOp == UNARYPLUS )
  {
	postFixVarStack.push_back(' ');
	if(rhs < 0)
		postFixStack.push_back( rhs * -1 );
	else
		postFixStack.push_back( rhs );
  }
  else if ( topOp == MULT )
	{
		postFixVarStack.push_back(' ');
		postFixStack.push_back( lhs * rhs );
  }
  else if( topOp == MOD)
  {
	  postFixVarStack.push_back(' ');
	  postFixStack.push_back( lhs % rhs);
  }
  else if( topOp == OR)
  {
	  postFixVarStack.push_back(' ');
	  postFixStack.push_back( lhs | rhs);
  }
  else if ( topOp == LOGICALOR)
  {
	  postFixVarStack.push_back(' ');
	  postFixStack.push_back( lhs || rhs);
  }
  else if( topOp == AND)
  {
	  postFixVarStack.push_back(' ');
	  postFixStack.push_back( lhs & rhs);
  }
  else if( topOp == LOGICALAND)
  {
	  postFixVarStack.push_back(' ');
	  postFixStack.push_back( lhs && rhs);
  }
  else if( topOp == COMPLIMENT)
  {
	  postFixVarStack.push_back(' ');
	  postFixStack.push_back(~rhs);

  }
  else if( topOp == NEGATION)
  {
	  postFixVarStack.push_back(' ');
	  postFixStack.push_back(!rhs);

  }
  else if(topOp == GT)
  {
	  if(lhs > rhs)
	  {
		  postFixVarStack.push_back(' ');
		  postFixStack.push_back(1);
	  }
	  else
	  {
		  postFixVarStack.push_back(' ');
		  postFixStack.push_back(0); 
	  }
  }
  else if(topOp == LT)
  {
	  if(lhs < rhs)
	  {
		  postFixVarStack.push_back(' ');
		  postFixStack.push_back(1);
	  }
	  else
	  {
		  postFixVarStack.push_back(' ');
		  postFixStack.push_back(0); 
	  }
  } 
  else if( topOp == GTET)
  {
	  if( lhs >= rhs)
	  {
		  postFixVarStack.push_back(' ');
		  postFixStack.push_back(1);
	  }
	  else
	  {
		  postFixVarStack.push_back(' ');
		  postFixStack.push_back(0);
	  }
  }
  else if( topOp == LTET)
  {
	  if(lhs <= rhs)
	  {
		  postFixVarStack.push_back(' ');
		  postFixStack.push_back(1);
	  }
	  else
	  {
		  postFixVarStack.push_back(' ');
		  postFixStack.push_back(0);
	  }
  }
  else if( topOp == LS)
  {
	  postFixVarStack.push_back(' ');
	  postFixStack.push_back( lhs << rhs);
  }
  else if(topOp == RS)
  {
	  postFixVarStack.push_back(' ');
	  postFixStack.push_back(lhs >> rhs);
  }

  else if ( topOp == DIV ) 
    if ( rhs != 0 )
	{
	  postFixVarStack.push_back(' ');
      postFixStack.push_back( lhs / rhs );
	}
    else 
	{
      cerr << "Division by zero" << endl;
	  postFixVarStack.push_back(' ');
      postFixStack.push_back( lhs );
    }
 
  opStack.pop_back( );

 

}

// top and pop the postfix machine stack; return the result.
// If the stack is empty, print an error message.
template<class NumericType>
NumericType Evaluator<NumericType>::getTop( ) {
  if ( postFixStack.empty( ) ) {
    cerr << "Missing operand" << endl;
    return 0;
  }

  NumericType tmp = postFixStack.back( );
  postFixVarStack.pop_back();
  postFixStack.pop_back( );
  return tmp;
}
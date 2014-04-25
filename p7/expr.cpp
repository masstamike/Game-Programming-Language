

  Game_object *left = m_left->eval_game_object();
  Game_object *right = m_right->eval_game_object();

  return left->near(right);
  return left->touches(right);



  rect1 touches rect2;e 




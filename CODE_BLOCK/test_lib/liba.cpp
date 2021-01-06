
Morse::Morse(int pin)
{
  cout << "0" << endl;
  _pin = pin;
}

void Morse::dot()
{
    cout << "1-" << _pin << endl;
}

void Morse::dash()
{
  cout << "2-" << _pin << endl;
}

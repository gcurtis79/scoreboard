void soundInit()
{
  snd.speakerPin = SPK_PIN;
  if (!SD.begin())
  {
    for (uint8_t i = 0; i < 3; i++)
    {
      tone(9, 100, 75);
      delay(150);
    }
    return;
  }
}

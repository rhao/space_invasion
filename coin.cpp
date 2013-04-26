#include "coin.h"
#include "mainwindow.h"

Coin::Coin( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	count = 0;
}

void Coin::move()
{
	count++;
	if(count == 30)
	{
		window->removeCoin(this);
	}
}

namespace project
{

struct vecfade_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vecfade";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "2050.nT6K8ClCuU7O.nrPnvvJP6pZdfwEBecMaEiJHW2qYDOosKtHcPfCoHDRJ2GGFIv.ES0rIXS0JObKIfL.ACPm..oyXNYwTQSb3rhv2hcX4rXY1YAMgkpFcenTTUG33RqnZVg0hB2.EpNgerVMpFooElzPAKfMLDcqnYpUSngyqanrE8VklpT0AUYHQpVMfthxOzX8v7bivvVwx8R0xEHhHnnoJUJ1.KKdpRVpDyH5BC.GKKCNzoIEq1VQuzoY0bBXTwPYw3FNKHp0NyroAKpnIlGIUTpn4kp9vDvYg4Nmvlp58YBA1YQgpT33rjvXHNKpZjshZgEEZd4gdAGwYIwDL3rrnphwkRQ.t+bsWz8+cN+B1QGkL12s6slTdACNu+Mmzkb0TqZOCXsfnRVlTOfiLEUgJnhnvMvjsl0EfyLMofBplTpHIvPf.F9VDGtajTFK2.2dukoBDEysVmrrAVVHHFv7FoLQWIMSdz3a1AGHbm0M6PCmJGfIMerfcBmthEKegHJYnWJulev8BXGNqLnPTS33rrUzKWzzfMSoL1HIbbVq4cJQFToLSdyZHq4TF9wTRCTcRCGIzpFpNUQZZoJUACwBhdmS0qFFv4XtLB6mq8e680.bbdGgLFDdkzLuPkX0xX6asWx7UBdF5tGYO6et6NzkRm6t+7Xr4t6NG5e+Qn+bmeQZFAEPohrPzc6NqYLVLJaYKalyb2icrisrkc6vF1vN1wl4u90uF1vV1NyYtriMroLgBLyXrtYLFCgt28t+8uO9su8s28tG9+++2926++++tu0dt1+u6d2s78VLu8wN9eq8devKcQ12snTJoAcHoJFG.tn54cP4qcd2hRzJXrgu3+jsUik4ni4dO1fRd+4H17.Ywcx7i0d8KkvVFwETTtgIKkpxrELD1CW79671qiuF9fRLnVP44H+l4CEphnpKjaEC2f7gZicC0BNRUDDyA3ATcxg4zzrBpz7w5nYcy0Xs+49yOhXx4cziuKesW1jslEqYlnWFRqoY1b8tuTZpSyGbRXs00RgfpSbjGdKa9ywnlOV9QD9BBdDpBqTTkgFAF...R.fPa..f3.RoRspNBADDGC.F.MCBFC..B..GD...C..XPF.f...lDoX61kbpJHsw8APTI6rsGgIqLExg3v4fU0H1fbkf9NtXsKcFJPQmcipm++iNIbGM0xw6Kb3+9XfIxYNzXCUkZCkB.dxHsshHPLI9q7tnfQKyLkJviBURPlOxbkp24Munh0F4uziCueKrPhM8rVmgIjijIBfCfN5pjpRoo+TikjQctwKhIY1DIftw9hA6ElrvpZK.EoW0ZMRnQVT9Xam65aTMle2Lo+vBceRPCZNeUonlFgpEUV7vY1kkWLaSPpq2tPBCWFaXOv10enDSQ2DUlNekWfPzXoDZVVOFdEoiYFz6oetdG7EcwEQorJJWQhUIaF1Du0n3a1jk0WEyz5bq65uXKYPgsr648osob05t7sF.N0b9mu7hLuIRt5U4u06MKxa00fjmGAOGJUMOpQ7TBoy7r4lnYwG8OJTgp476sFlaQ5YgucnUng2Mazn.TIBUZxiktOEieagoLK95xxSiPozDuYgwqT1V1Ltaf2h4Y0DfnFzyrd34lXKFmFL+euSFuQQJvlBC6tnH8WKA218idLHEjPJjPE0GS146iGDjZoI5LLZbklLvdVEGBBszDkFNIvJSFruEggjjjoEMNQZfZNIXuqwoLIwPIJbhD.E7D.NNhkMYmgaSulAN6mE7axjThFKRQtNbNOOCMAN8+vfiE.imzuPDovzaUJJg9.IFEha8YwnkmUG5F.BLy7BlE1sDohPoGPhAlVfawuIOUGpF.DvL.ySPxlnyj2RVCCB6FBlNE2JFl6HJSyAjRICarStolvVMvLZ3pSEcjBa1QIgDpCnXTHt0mUiVdTcnZ.HPNCyKXVriorZBKJg0GT.WEItZ1pal01QfnC1e.wnFXZqVxr6hbrZ0zjAymHQRm.PUobcfOE1jeVeHbMsQo+b3.09yZxLv1tfjUJBjWDiCrohJGcyFcv14VMGDiB6nF1iRk2IZRTQRDrqhJAzXPDYGhpIflgwLzpsN5HPjw.WcH5dfLFBX45X6U.iEDLZFzCuBOcjuhxqdvCKrEII+ZMuZFbKDbU2BLWJDUyKjHITxeGozaMtSaw.axbBojPASCPcFWXW0YqPUFXmFBFf3EQ7OuDf0mA3hNzQakOtrAaA3oSus9dmcaMNfLu.BPfva8YX8Rbm3j0MMOaSrfe3JaTD7Er3+2Ds69iFItH6Z3mDA9oDvuf.Rv5Pi1eqIw2Xk0iIFCtL4TOQ8JhxnG1pAsD.UtrBoSFwIyjLkmQi7V5sHvLAzJs7.jI8gmYNUt6rysUeRyEsE4icvV1k5lJvhH.xTuQ+Fj7sZfV1+Yks1wJ2Jvz6joUvjjMoPsA4GgGOkwkP3P7eo4+ncu3tOcVoel3n7SYCgWJ.xoDGDyBCwSirq+B+85Qd6M75ZDTynB7yf+LXAdwjdrIBP4UNpFgeNFDqQ+adAnGpolsuZBBGbFCdjniNQQoK9tynB+68YoZ0SvmRZ5ovHcMiFjNQP6s8Io6wjwy4O4yRAW47Sc5GnqQyZf.TF4.QPEvpZDWmaLsjoHF8CKEGREau6.elQHlUnVeMv0W83PCCMKaEEx1ZXAI2.u2AcBrXqPC9dbfqpBAPn9y2FNsHQAEZeEJjNKV+eKU8QiCu8njajdCv+5A";
	}
};
}


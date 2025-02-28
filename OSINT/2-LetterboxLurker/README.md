# Letterbox Lurker - OSINT
This is the README for OSINT/3.

FLAG: parsec{chris_geraint_westminster}, parsec{christopher_geraint_westminster}


### Question

I was on a trip to the UK before COVID hit and I came across some an interesting shiny postbox. I did not pay much attention to it but it was in the back of my head. Some one and a half years ago, I visited the UK again and I came across this red, white and blue postbox. My friend told me the Royal Mail paints these for special occasions and it has been a thing for quite a while now. Very intruiging! I started a hunt for similar such postboxes and came across different colours as well. Your job here is to:
- Find the specially painted shiny postboxes _closest to_ the ones painted red, white and blue, and
  - if they were associated with a person, enter their first names (in alphabetical order) (e.g., if two of them were painted in honour of John Doe and Michael Smith, append john_michael)
  - if they were associated with a place, enter the first word of the place (in alphabetical order) (E.g. if two of them were painted in relation to Church Street, Vatican City, append church_vatican)
  - then, sort all words in alphabetical order
  - Finally, the flag will be parsec{church_john_michael_vatican}
  
### How do I find the postboxes?

1. The red white and blue postboxes were made for the King's coronation in May 2023.
2. Searching up news sites, the locations of the red, white and blue postboxes are revealed. 
3. https://metro.co.uk/2023/05/03/special-postboxes-unveiled-in-celebration-of-the-kings-coronation-18714409/
4. The postboxes are located in London, Edinburgh, Cardiff and County Down (Norther Ireland)
5. Searching up "United Kingdom Shiny postboxes", we land up at https://specialpostbox.com/
6. The description says "Welcome to our website Special Postbox where we record all of the special postboxes from around the UK that Royal Mail installs, including the London 2012 Olympic gold postboxes."
7. Great! The gold postboxes might be the "shiny" ones the author is talking about.
8. Searching up Google Maps matching the locations and finding the nearest special gold postboxes, we get the description of the gold postbox in the Special Postbox Finder website.

### Special Postbox Finder
- [GOLD (CARDIFF) - Geraint Thomas - Cycling - Men’s team pursuit](https://specialpostbox.com/2024/08/07/geraint-thomas-cycling-mens-team-pursuit/)
- [GOLD (LONDON) - Westminster Abbey - Project launch](https://specialpostbox.com/2024/08/07/westminster-abbey-project-launch/)
- [GOLD (SCOTLAND) - Chris Hoy - Cycling - Men’s Keirin](https://specialpostbox.com/2024/08/07/chris-hoy-cycling-mens-keirin/)
- [GOLD (SCOTLAND) - Chris Hoy - Cycling - Men’s team sprint](https://specialpostbox.com/2024/08/07/chris-hoy-cycling-mens-team-sprint/)

### Red White and Blue Postboxes
- [RWB - 3 St John St (CARDIFF)](https://www.google.com/maps/@51.4809362,-3.1784656,3a,27.1y,133.9h,82.77t/data=!3m7!1e1!3m5!1sjNJbQdyp7qdw23klOJN0YA!2e0!6shttps:%2F%2Fstreetviewpixels-pa.googleapis.com%2Fv1%2Fthumbnail%3Fcb_client%3Dmaps_sv.tactile%26w%3D900%26h%3D600%26pitch%3D7.230000000000004%26panoid%3DjNJbQdyp7qdw23klOJN0YA%26yaw%3D133.9!7i16384!8i8192)
- [RWB - 11 Ballynahinch St (IRELAND)](https://www.google.com/maps/@54.4631423,-6.0824415,3a,75y,321.37h,64.05t/data=!3m7!1e1!3m5!1sa9UehJ6-w9H_FzYYJ985Rg!2e0!6shttps:%2F%2Fstreetviewpixels-pa.googleapis.com%2Fv1%2Fthumbnail%3Fcb_client%3Dmaps_sv.tactile%26w%3D900%26h%3D600%26pitch%3D25.948345186190195%26panoid%3Da9UehJ6-w9H_FzYYJ985Rg%26yaw%3D321.36569858574614!7i16384!8i8192)
- [RWB? - 18 Howe St (SCOTLAND)](https://www.google.com/maps/@55.9562107,-3.2022724,3a,75y,117.19h,92.93t/data=!3m7!1e1!3m5!1sHyFpp3OSCXjJ1y0VHJDDkw!2e0!6shttps:%2F%2Fstreetviewpixels-pa.googleapis.com%2Fv1%2Fthumbnail%3Fcb_client%3Dmaps_sv.tactile%26w%3D900%26h%3D600%26pitch%3D-2.9319866297952473%26panoid%3DHyFpp3OSCXjJ1y0VHJDDkw%26yaw%3D117.18984249415709!7i16384!8i8192)
- [RWB - Great College St (LONDON)](https://www.google.com/maps/@51.4975705,-0.1257098,3a,75y,258.6h,90t/data=!3m7!1e1!3m5!1sKw0z-53FB_Xds0_rME7gyA!2e0!6shttps:%2F%2Fstreetviewpixels-pa.googleapis.com%2Fv1%2Fthumbnail%3Fcb_client%3Dmaps_sv.tactile%26w%3D900%26h%3D600%26pitch%3D0%26panoid%3DKw0z-53FB_Xds0_rME7gyA%26yaw%3D258.6!7i13312!8i6656)

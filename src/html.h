
char* responseHTML = R"=====(

<!DOCTYPE html>
<html lang='en'>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
       
        <style>
            h1.welcome, h3 {
                color: #fff!important;
                text-align: center;
                font-family: sans-serif;
                font-weight: 400;
                margin-bottom: 10px;
                font-size: 29px;
            }
            .portal-bg {
                background-color: #000;
                margin: 0;
            }
            .nav {
                max-width: 500px;
                margin: 0 auto;
            }
            .icons-row a img {
                width: 70px;
            }

            .icons-row.color-row .button {
                width: 25%;
            }

            .icons-row.bright-row .button, .icons-row.speed-row .button {
                width: 33.33%;
            }

            .icons-row .button {
                
                display: block;
                float: left;
                text-align: center;
            }
            .icons-row .button i {
                font-size: 77px;
                display: none;
            }
            .row {
                float: left;
                width: 100%;
                padding-bottom: 10px;
                border-bottom: solid 1px #555;
            }
            .icons-row {
                /* margin-top: 31px; */
            }

            .button:hover img {
                opacity: 1;
                -webkit-animation: flash 1.5s;
                animation: flash 1.5s;
            }
            @-webkit-keyframes flash {
                0% {
                    opacity: .4;
                }
                100% {
                    opacity: 1;
                }
            }
            @keyframes flash {
                0% {
                    opacity: .4;
                }
                100% {
                    opacity: 1;
                }
            }
            .row a {
                color: white;
                display: block;
                padding: 10px 4px;
            }
            .row a:hover {
                background-color: #333;
                cursor: pointer;
            }
            .row a svg {
                fill: white;
                height: 62px;
                max-width: 62px;
            }
            .row a .round {
                height: 62px;
                max-width: 62px;
                display: block;
                margin: 0 auto;
                background-color: red;
                border-radius: 38px 20px;
            }
            .color-red a .round {
                background-color: red;
            }
            .color-green a .round {
                background-color: green;
            }
            .color-yellow a .round {
                background-color: yellow;
            }
            .color-blue a .round {
                background-color: blue;
            }
        
            .icons-row button {
                height: 30px;
                width: 100%;
                border: none;
                background: none;
                color: #fff;
                font-size: 17px;
                text-align: center;
                padding: 0;
            }
            .bottom {
                padding: 10px 0px;
                height: 22px;
            }
            .bottom .copyright {
                width: 50%;
                float: left;
            }
            .bottom .copyright {
                color: #fff;
            }
            .bottom .media {
                width: 50%;
                float: right;
            }
            .bottom .media span {
                float: right;
                color: #fff;
            }
            .bottom .media svg {
                fill: white;
                width: 21px;
                float: right;
                margin-left: 10px;
            }
        </style>
        
    </head>
    <body>
        <body class="portal-bg" id="portal">

            <div class="nav">
                <!-- <h1 class="welcome">PowerKIT x LUCERNA</h1> -->
                <h1 class="welcome">Налаштування LUCERNA</h1>
                <div class="text-center">
                    <div class="wrapper-custom">
                        <div class="row">
                            <!-- <h3>Select color</h3> -->
                            <h3>Обери колір</h3>
                            <div class="icons-row color-row">
                                <div class="button color-red">
                                    <a href='/red'>
                                        <span class="round"></span>
                                        <!-- <button class="btn btn-outline-danger" type="button">Red</button> -->
                                        <button class="btn btn-outline-danger" type="button">Червоний</button>
                                    </a>
                                </div>
                                <div class="button color-yellow">
                                    <a href='/yellow'>
                                        <span class="round"></span>
                                         <!-- <button class="btn btn-outline-warning" type="button">Yellow</button> -->
                                        <button class="btn btn-outline-warning" type="button">Жовтий</button>
                                    </a>
                                </div>
                                <div class="button color-green">
                                    <a href='/green'>
                                        <span class="round"></span>
                                          <!-- <button class="btn btn-outline-success" type="button">Green</button> -->
                                        <button class="btn btn-outline-success" type="button">Зелений</button>
                                    </a>
                                </div>
                                <div class="button color-blue">
                                    <a href='/blue'>
                                        <span class="round"></span>
                                        <!-- <button class="btn btn-outline-primary" type="button">Blue</button> -->
                                        <button class="btn btn-outline-primary" type="button">Синій</button>
                                    </a>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <!-- <h3>Select Type</h3> -->
                            <h3>Тип світла</h3>
                            <div class="icons-row color-row">
                                <div class="button">
                                    <a href='/light_fire'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 448 512"><path d="M159.3 5.4c7.8-7.3 19.9-7.2 27.7 .1c27.6 25.9 53.5 53.8 77.7 84c11-14.4 23.5-30.1 37-42.9c7.9-7.4 20.1-7.4 28 .1c34.6 33 63.9 76.6 84.5 118c20.3 40.8 33.8 82.5 33.8 111.9C448 404.2 348.2 512 224 512C98.4 512 0 404.1 0 276.5c0-38.4 17.8-85.3 45.4-131.7C73.3 97.7 112.7 48.6 159.3 5.4zM225.7 416c25.3 0 47.7-7 68.8-21c42.1-29.4 53.4-88.2 28.1-134.4c-4.5-9-16-9.6-22.5-2l-25.2 29.3c-6.6 7.6-18.5 7.4-24.7-.5c-16.5-21-46-58.5-62.8-79.8c-6.3-8-18.3-8.1-24.7-.1c-33.8 42.5-50.8 69.3-50.8 99.4C112 375.4 162.6 416 225.7 416z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Fire</button> -->
                                        <button type="button" class="btn btn-outline-light">Вогонь</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/light_ocean'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 640 512"><path d="M128 64c0-17.7 14.3-32 32-32H320c17.7 0 32 14.3 32 32V416h96V256c0-17.7 14.3-32 32-32H608c17.7 0 32 14.3 32 32s-14.3 32-32 32H512V448c0 17.7-14.3 32-32 32H320c-17.7 0-32-14.3-32-32V96H192V256c0 17.7-14.3 32-32 32H32c-17.7 0-32-14.3-32-32s14.3-32 32-32h96V64z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Wave</button> -->
                                        <button type="button" class="btn btn-outline-light">Хвилі</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/light_strips'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><path d="M256 96c0-53 43-96 96-96h38.4C439.9 0 480 40.1 480 89.6V176v16V376c0 75.1-60.9 136-136 136s-136-60.9-136-136V296c0-22.1-17.9-40-40-40s-40 17.9-40 40V464c0 26.5-21.5 48-48 48s-48-21.5-48-48V296c0-75.1 60.9-136 136-136s136 60.9 136 136v80c0 22.1 17.9 40 40 40s40-17.9 40-40V192H352c-53 0-96-43-96-96zm144-8a24 24 0 1 0 -48 0 24 24 0 1 0 48 0z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Snake</button> -->
                                        <button type="button" class="btn btn-outline-light">Змійка</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/light_temperature'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 640 512"><path d="M320 96C178.6 96 64 210.6 64 352v96c0 17.7-14.3 32-32 32s-32-14.3-32-32V352C0 175.3 143.3 32 320 32s320 143.3 320 320v96c0 17.7-14.3 32-32 32s-32-14.3-32-32V352C576 210.6 461.4 96 320 96zm0 192c-35.3 0-64 28.7-64 64v96c0 17.7-14.3 32-32 32s-32-14.3-32-32V352c0-70.7 57.3-128 128-128s128 57.3 128 128v96c0 17.7-14.3 32-32 32s-32-14.3-32-32V352c0-35.3-28.7-64-64-64zM160 352v96c0 17.7-14.3 32-32 32s-32-14.3-32-32V352c0-123.7 100.3-224 224-224s224 100.3 224 224v96c0 17.7-14.3 32-32 32s-32-14.3-32-32V352c0-88.4-71.6-160-160-160s-160 71.6-160 160z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Rainbow</button> -->
                                        <button type="button" class="btn btn-outline-light">Веселка</button>
                                    </a>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <!-- <h3>Select Sound</h3> -->
                            <h3>Обери звуки</h3>
                            <div class="icons-row color-row">
                                <div class="button">
                                    <a href='/sound_fire'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 384 512"><path d="M372.5 256.5l-.7-1.9C337.8 160.8 282 76.5 209.1 8.5l-3.3-3C202.1 2 197.1 0 192 0s-10.1 2-13.8 5.5l-3.3 3C102 76.5 46.2 160.8 12.2 254.6l-.7 1.9C3.9 277.3 0 299.4 0 321.6C0 426.7 86.8 512 192 512s192-85.3 192-190.4c0-22.2-3.9-44.2-11.5-65.1zm-90.8 49.5c4.1 9.3 6.2 19.4 6.2 29.5c0 53-43 96.5-96 96.5s-96-43.5-96-96.5c0-10.1 2.1-20.3 6.2-29.5l1.9-4.3c15.8-35.4 37.9-67.7 65.3-95.1l8.9-8.9c3.6-3.6 8.5-5.6 13.6-5.6s10 2 13.6 5.6l8.9 8.9c27.4 27.4 49.6 59.7 65.3 95.1l1.9 4.3z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Fireplace</button> -->
                                        <button type="button" class="btn btn-outline-light">Багаття</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/sound_birds'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><path d="M160.8 96.5c14 17 31 30.9 49.5 42.2c25.9 15.8 53.7 25.9 77.7 31.6V138.8C265.8 108.5 250 71.5 248.6 28c-.4-11.3-7.5-21.5-18.4-24.4c-7.6-2-15.8-.2-21 5.8c-13.3 15.4-32.7 44.6-48.4 87.2zM320 144v30.6l0 0v1.3l0 0 0 32.1c-60.8-5.1-185-43.8-219.3-157.2C97.4 40 87.9 32 76.6 32c-7.9 0-15.3 3.9-18.8 11C46.8 65.9 32 112.1 32 176c0 116.9 80.1 180.5 118.4 202.8L11.8 416.6C6.7 418 2.6 421.8 .9 426.8s-.8 10.6 2.3 14.8C21.7 466.2 77.3 512 160 512c3.6 0 7.2-1.2 10-3.5L245.6 448H320c88.4 0 160-71.6 160-160V128l29.9-44.9c1.3-2 2.1-4.4 2.1-6.8c0-6.8-5.5-12.3-12.3-12.3H400c-44.2 0-80 35.8-80 80zm80-16a16 16 0 1 1 0 32 16 16 0 1 1 0-32z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Birds</button> -->
                                        <button type="button" class="btn btn-outline-light">Лісні Птахи</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/sound_sea'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 576 512"><path d="M269.5 69.9c11.1-7.9 25.9-7.9 37 0C329 85.4 356.5 96 384 96c26.9 0 55.4-10.8 77.4-26.1l0 0c11.9-8.5 28.1-7.8 39.2 1.7c14.4 11.9 32.5 21 50.6 25.2c17.2 4 27.9 21.2 23.9 38.4s-21.2 27.9-38.4 23.9c-24.5-5.7-44.9-16.5-58.2-25C449.5 149.7 417 160 384 160c-31.9 0-60.6-9.9-80.4-18.9c-5.8-2.7-11.1-5.3-15.6-7.7c-4.5 2.4-9.7 5.1-15.6 7.7c-19.8 9-48.5 18.9-80.4 18.9c-33 0-65.5-10.3-94.5-25.8c-13.4 8.4-33.7 19.3-58.2 25c-17.2 4-34.4-6.7-38.4-23.9s6.7-34.4 23.9-38.4C42.8 92.6 61 83.5 75.3 71.6c11.1-9.5 27.3-10.1 39.2-1.7l0 0C136.7 85.2 165.1 96 192 96c27.5 0 55-10.6 77.5-26.1zm37 288C329 373.4 356.5 384 384 384c26.9 0 55.4-10.8 77.4-26.1l0 0c11.9-8.5 28.1-7.8 39.2 1.7c14.4 11.9 32.5 21 50.6 25.2c17.2 4 27.9 21.2 23.9 38.4s-21.2 27.9-38.4 23.9c-24.5-5.7-44.9-16.5-58.2-25C449.5 437.7 417 448 384 448c-31.9 0-60.6-9.9-80.4-18.9c-5.8-2.7-11.1-5.3-15.6-7.7c-4.5 2.4-9.7 5.1-15.6 7.7c-19.8 9-48.5 18.9-80.4 18.9c-33 0-65.5-10.3-94.5-25.8c-13.4 8.4-33.7 19.3-58.2 25c-17.2 4-34.4-6.7-38.4-23.9s6.7-34.4 23.9-38.4c18.1-4.2 36.2-13.3 50.6-25.2c11.1-9.4 27.3-10.1 39.2-1.7l0 0C136.7 373.2 165.1 384 192 384c27.5 0 55-10.6 77.5-26.1c11.1-7.9 25.9-7.9 37 0zm0-144C329 229.4 356.5 240 384 240c26.9 0 55.4-10.8 77.4-26.1l0 0c11.9-8.5 28.1-7.8 39.2 1.7c14.4 11.9 32.5 21 50.6 25.2c17.2 4 27.9 21.2 23.9 38.4s-21.2 27.9-38.4 23.9c-24.5-5.7-44.9-16.5-58.2-25C449.5 293.7 417 304 384 304c-31.9 0-60.6-9.9-80.4-18.9c-5.8-2.7-11.1-5.3-15.6-7.7c-4.5 2.4-9.7 5.1-15.6 7.7c-19.8 9-48.5 18.9-80.4 18.9c-33 0-65.5-10.3-94.5-25.8c-13.4 8.4-33.7 19.3-58.2 25c-17.2 4-34.4-6.7-38.4-23.9s6.7-34.4 23.9-38.4c18.1-4.2 36.2-13.3 50.6-25.2c11.1-9.5 27.3-10.1 39.2-1.7l0 0C136.7 229.2 165.1 240 192 240c27.5 0 55-10.6 77.5-26.1c11.1-7.9 25.9-7.9 37 0z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Ocean</button> -->
                                        <button type="button" class="btn btn-outline-light">Морські хвилі</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/sound_rain'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 576 512"><path d="M224 0c38.6 0 71.9 22.8 87.2 55.7C325.7 41.1 345.8 32 368 32c38.7 0 71 27.5 78.4 64H448c35.3 0 64 28.7 64 64s-28.7 64-64 64H128c-35.3 0-64-28.7-64-64s28.7-64 64-64c0-53 43-96 96-96zM140.6 292.3l-48 80c-6.8 11.4-21.6 15-32.9 8.2s-15.1-21.6-8.2-32.9l48-80c6.8-11.4 21.6-15.1 32.9-8.2s15.1 21.6 8.2 32.9zm327.8-32.9c11.4 6.8 15 21.6 8.2 32.9l-48 80c-6.8 11.4-21.6 15-32.9 8.2s-15-21.6-8.2-32.9l48-80c6.8-11.4 21.6-15.1 32.9-8.2zM252.6 292.3l-48 80c-6.8 11.4-21.6 15-32.9 8.2s-15.1-21.6-8.2-32.9l48-80c6.8-11.4 21.6-15.1 32.9-8.2s15.1 21.6 8.2 32.9zm103.8-32.9c11.4 6.8 15 21.6 8.2 32.9l-48 80c-6.8 11.4-21.6 15-32.9 8.2s-15.1-21.6-8.2-32.9l48-80c6.8-11.4 21.6-15.1 32.9-8.2zM306.5 421.9C329 437.4 356.5 448 384 448c26.9 0 55.4-10.8 77.4-26.1l0 0c11.9-8.5 28.1-7.8 39.2 1.7c14.4 11.9 32.5 21 50.6 25.2c17.2 4 27.9 21.2 23.9 38.4s-21.2 27.9-38.4 23.9c-24.5-5.7-44.9-16.5-58.2-25C449.5 501.7 417 512 384 512c-31.9 0-60.6-9.9-80.4-18.9c-5.8-2.7-11.1-5.3-15.6-7.7c-4.5 2.4-9.7 5.1-15.6 7.7c-19.8 9-48.5 18.9-80.4 18.9c-33 0-65.5-10.3-94.5-25.8c-13.4 8.4-33.7 19.3-58.2 25c-17.2 4-34.4-6.7-38.4-23.9s6.7-34.4 23.9-38.4c18.1-4.2 36.2-13.3 50.6-25.2c11.1-9.4 27.3-10.1 39.2-1.7l0 0C136.7 437.2 165.1 448 192 448c27.5 0 55-10.6 77.5-26.1c11.1-7.9 25.9-7.9 37 0z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Rain</button> -->
                                        <button type="button" class="btn btn-outline-light">Літній Дощ</button>
                                    </a>
                                </div>

                                <div class="button">
                                    <a href='/sound_crickets'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 384 512"><path d="M223.5 32C100 32 0 132.3 0 256S100 480 223.5 480c60.6 0 115.5-24.2 155.8-63.4c5-4.9 6.3-12.5 3.1-18.7s-10.1-9.7-17-8.5c-9.8 1.7-19.8 2.6-30.1 2.6c-96.9 0-175.5-78.8-175.5-176c0-65.8 36-123.1 89.3-153.3c6.1-3.5 9.2-10.5 7.7-17.3s-7.3-11.9-14.3-12.5c-6.3-.5-12.6-.8-19-.8z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Rain</button> -->
                                        <button type="button" class="btn btn-outline-light">Вечір Цвіркуни</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/sound_chikens'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 384 512"><path d="M384 312.7c-55.1 136.7-187.1 54-187.1 54-40.5 81.8-107.4 134.4-184.6 134.7-16.1 0-16.6-24.4 0-24.4 64.4-.3 120.5-42.7 157.2-110.1-41.1 15.9-118.6 27.9-161.6-82.2 109-44.9 159.1 11.2 178.3 45.5 9.9-24.4 17-50.9 21.6-79.7 0 0-139.7 21.9-149.5-98.1 119.1-47.9 152.6 76.7 152.6 76.7 1.6-16.7 3.3-52.6 3.3-53.4 0 0-106.3-73.7-38.1-165.2 124.6 43 61.4 162.4 61.4 162.4 .5 1.6 .5 23.8 0 33.4 0 0 45.2-89 136.4-57.5-4.2 134-141.9 106.4-141.9 106.4-4.4 27.4-11.2 53.4-20 77.5 0 0 83-91.8 172-20z"/></svg>                                      
                                             <!-- <button type="button" class="btn btn-outline-light">Rain</button> -->
                                        <button type="button" class="btn btn-outline-light">Українське Село</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/sound_train'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 448 512"><path d="M96 0C43 0 0 43 0 96V352c0 48 35.2 87.7 81.1 94.9l-46 46C28.1 499.9 33.1 512 43 512H82.7c8.5 0 16.6-3.4 22.6-9.4L160 448H288l54.6 54.6c6 6 14.1 9.4 22.6 9.4H405c10 0 15-12.1 7.9-19.1l-46-46c46-7.1 81.1-46.9 81.1-94.9V96c0-53-43-96-96-96H96zM64 128c0-17.7 14.3-32 32-32h80c17.7 0 32 14.3 32 32v96c0 17.7-14.3 32-32 32H96c-17.7 0-32-14.3-32-32V128zM272 96h80c17.7 0 32 14.3 32 32v96c0 17.7-14.3 32-32 32H272c-17.7 0-32-14.3-32-32V128c0-17.7 14.3-32 32-32zM64 352a32 32 0 1 1 64 0 32 32 0 1 1 -64 0zm288-32a32 32 0 1 1 0 64 32 32 0 1 1 0-64z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Rain</button> -->
                                        <button type="button" class="btn btn-outline-light">Укр. Залізниця</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/sound_frogs'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 576 512"><path d="M368 32c41.7 0 75.9 31.8 79.7 72.5l85.6 26.3c25.4 7.8 42.8 31.3 42.8 57.9c0 21.8-11.7 41.9-30.7 52.7L400.8 323.5 493.3 416H544c17.7 0 32 14.3 32 32s-14.3 32-32 32H480c-8.5 0-16.6-3.4-22.6-9.4L346.9 360.2c11.7-36 3.2-77.1-25.4-105.7c-40.6-40.6-106.3-40.6-146.9-.1L101 324.4c-6.4 6.1-6.7 16.2-.6 22.6s16.2 6.6 22.6 .6l73.8-70.2 .1-.1 .1-.1c3.5-3.5 7.3-6.6 11.3-9.2c27.9-18.5 65.9-15.4 90.5 9.2c24.7 24.7 27.7 62.9 9 90.9c-2.6 3.8-5.6 7.5-9 10.9L261.8 416H352c17.7 0 32 14.3 32 32s-14.3 32-32 32H64c-35.3 0-64-28.7-64-64C0 249.6 127 112.9 289.3 97.5C296.2 60.2 328.8 32 368 32zm0 104a24 24 0 1 0 0-48 24 24 0 1 0 0 48z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Rain</button> -->
                                        <button type="button" class="btn btn-outline-light">Озеро Жаби</button>
                                    </a>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <!-- <h3>Chose Brightness</h3> -->
                            <h3>Швидкість світла</h3>
                            <div class="icons-row speed-row">
                                <div class="button">
                                    <a href='/speed_low'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><path d="M0 256a256 256 0 1 1 512 0A256 256 0 1 1 0 256zm320 96c0-26.9-16.5-49.9-40-59.3V88c0-13.3-10.7-24-24-24s-24 10.7-24 24V292.7c-23.5 9.5-40 32.5-40 59.3c0 35.3 28.7 64 64 64s64-28.7 64-64z"/></svg>                                       
                                        <!-- <button type="button" class="btn btn-outline-light">Low</button> -->
                                        <button type="button" class="btn btn-outline-light">Мала</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/speed_medium'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><path d="M0 256a256 256 0 1 1 512 0A256 256 0 1 1 0 256zm320 96c0-26.9-16.5-49.9-40-59.3V88c0-13.3-10.7-24-24-24s-24 10.7-24 24V292.7c-23.5 9.5-40 32.5-40 59.3c0 35.3 28.7 64 64 64s64-28.7 64-64zM144 176a32 32 0 1 0 0-64 32 32 0 1 0 0 64zm-16 80a32 32 0 1 0 -64 0 32 32 0 1 0 64 0zm288 32a32 32 0 1 0 0-64 32 32 0 1 0 0 64zM400 144a32 32 0 1 0 -64 0 32 32 0 1 0 64 0z"/></svg>                                       
                                        <!-- <button type="button" class="btn btn-outline-light">Medium</button> -->
                                        <button type="button" class="btn btn-outline-light">Середя</button>
                                    </a>
                                </div> 
                                <div class="button">
                                    <a href='/speed_high'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><path d="M0 256a256 256 0 1 1 512 0A256 256 0 1 1 0 256zM288 96a32 32 0 1 0 -64 0 32 32 0 1 0 64 0zM256 416c35.3 0 64-28.7 64-64c0-17.4-6.9-33.1-18.1-44.6L366 161.7c5.3-12.1-.2-26.3-12.3-31.6s-26.3 .2-31.6 12.3L257.9 288c-.6 0-1.3 0-1.9 0c-35.3 0-64 28.7-64 64s28.7 64 64 64zM176 144a32 32 0 1 0 -64 0 32 32 0 1 0 64 0zM96 288a32 32 0 1 0 0-64 32 32 0 1 0 0 64zm352-32a32 32 0 1 0 -64 0 32 32 0 1 0 64 0z"/></svg>
                                         <!-- <button type="button" class="btn btn-outline-light">High</button> -->
                                        <button type="button" class="btn btn-outline-light">Велика</button>
                                    </a>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <!-- <h3>Chose Brightness</h3> -->
                            <h3>Інтенсивність світла</h3>
                            <div class="icons-row bright-row">
                                <div class="button">
                                    <a href='/bright_low'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><path d="M375.7 19.7c-1.5-8-6.9-14.7-14.4-17.8s-16.1-2.2-22.8 2.4L256 61.1 173.5 4.2c-6.7-4.6-15.3-5.5-22.8-2.4s-12.9 9.8-14.4 17.8l-18.1 98.5L19.7 136.3c-8 1.5-14.7 6.9-17.8 14.4s-2.2 16.1 2.4 22.8L61.1 256 4.2 338.5c-4.6 6.7-5.5 15.3-2.4 22.8s9.8 13 17.8 14.4l98.5 18.1 18.1 98.5c1.5 8 6.9 14.7 14.4 17.8s16.1 2.2 22.8-2.4L256 450.9l82.5 56.9c6.7 4.6 15.3 5.5 22.8 2.4s12.9-9.8 14.4-17.8l18.1-98.5 98.5-18.1c8-1.5 14.7-6.9 17.8-14.4s2.2-16.1-2.4-22.8L450.9 256l56.9-82.5c4.6-6.7 5.5-15.3 2.4-22.8s-9.8-12.9-17.8-14.4l-98.5-18.1L375.7 19.7zM269.6 110l65.6-45.2 14.4 78.3c1.8 9.8 9.5 17.5 19.3 19.3l78.3 14.4L402 242.4c-5.7 8.2-5.7 19 0 27.2l45.2 65.6-78.3 14.4c-9.8 1.8-17.5 9.5-19.3 19.3l-14.4 78.3L269.6 402c-8.2-5.7-19-5.7-27.2 0l-65.6 45.2-14.4-78.3c-1.8-9.8-9.5-17.5-19.3-19.3L64.8 335.2 110 269.6c5.7-8.2 5.7-19 0-27.2L64.8 176.8l78.3-14.4c9.8-1.8 17.5-9.5 19.3-19.3l14.4-78.3L242.4 110c8.2 5.7 19 5.7 27.2 0zM256 368a112 112 0 1 0 0-224 112 112 0 1 0 0 224zM192 256a64 64 0 1 1 128 0 64 64 0 1 1 -128 0z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Low</button> -->
                                        <button type="button" class="btn btn-outline-light">Мала</button>
                                    </a>
                                </div>
                                <div class="button">
                                    <a href='/bright_medium'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><path d="M375.7 19.7c-1.5-8-6.9-14.7-14.4-17.8s-16.1-2.2-22.8 2.4L256 61.1 173.5 4.2c-6.7-4.6-15.3-5.5-22.8-2.4s-12.9 9.8-14.4 17.8l-18.1 98.5L19.7 136.3c-8 1.5-14.7 6.9-17.8 14.4s-2.2 16.1 2.4 22.8L61.1 256 4.2 338.5c-4.6 6.7-5.5 15.3-2.4 22.8s9.8 13 17.8 14.4l98.5 18.1 18.1 98.5c1.5 8 6.9 14.7 14.4 17.8s16.1 2.2 22.8-2.4L256 450.9l82.5 56.9c6.7 4.6 15.3 5.5 22.8 2.4s12.9-9.8 14.4-17.8l18.1-98.5 98.5-18.1c8-1.5 14.7-6.9 17.8-14.4s2.2-16.1-2.4-22.8L450.9 256l56.9-82.5c4.6-6.7 5.5-15.3 2.4-22.8s-9.8-12.9-17.8-14.4l-98.5-18.1L375.7 19.7zM269.6 110l65.6-45.2 14.4 78.3c1.8 9.8 9.5 17.5 19.3 19.3l78.3 14.4L402 242.4c-5.7 8.2-5.7 19 0 27.2l45.2 65.6-78.3 14.4c-9.8 1.8-17.5 9.5-19.3 19.3l-14.4 78.3L269.6 402c-8.2-5.7-19-5.7-27.2 0l-65.6 45.2-14.4-78.3c-1.8-9.8-9.5-17.5-19.3-19.3L64.8 335.2 110 269.6c5.7-8.2 5.7-19 0-27.2L64.8 176.8l78.3-14.4c9.8-1.8 17.5-9.5 19.3-19.3l14.4-78.3L242.4 110c8.2 5.7 19 5.7 27.2 0zM256 368a112 112 0 1 0 0-224 112 112 0 1 0 0 224zM192 256a64 64 0 1 1 128 0 64 64 0 1 1 -128 0z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">Medium</button> -->
                                        <button type="button" class="btn btn-outline-light">Середя</button>
                                    </a>
                                </div> 
                                <div class="button">
                                    <a href='/bright_high'>
                                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><path d="M361.5 1.2c5 2.1 8.6 6.6 9.6 11.9L391 121l107.9 19.8c5.3 1 9.8 4.6 11.9 9.6s1.5 10.7-1.6 15.2L446.9 256l62.3 90.3c3.1 4.5 3.7 10.2 1.6 15.2s-6.6 8.6-11.9 9.6L391 391 371.1 498.9c-1 5.3-4.6 9.8-9.6 11.9s-10.7 1.5-15.2-1.6L256 446.9l-90.3 62.3c-4.5 3.1-10.2 3.7-15.2 1.6s-8.6-6.6-9.6-11.9L121 391 13.1 371.1c-5.3-1-9.8-4.6-11.9-9.6s-1.5-10.7 1.6-15.2L65.1 256 2.8 165.7c-3.1-4.5-3.7-10.2-1.6-15.2s6.6-8.6 11.9-9.6L121 121 140.9 13.1c1-5.3 4.6-9.8 9.6-11.9s10.7-1.5 15.2 1.6L256 65.1 346.3 2.8c4.5-3.1 10.2-3.7 15.2-1.6zM160 256a96 96 0 1 1 192 0 96 96 0 1 1 -192 0zm224 0a128 128 0 1 0 -256 0 128 128 0 1 0 256 0z"/></svg>
                                        <!-- <button type="button" class="btn btn-outline-light">High</button> -->
                                        <button type="button" class="btn btn-outline-light">Потужна</button>
                                    </a>
                                </div>
                            </div>
                        </div>
                      
                    </div>
                </div>


                <div class="bottom">
                    <div class="copyright">
                        <span>© Lucerna Зроблено в Україні</span>
                    </div>
                    <div class="media">
                        <span>
                            @lucerna.com.ua
                        </span>
                    </div>
                
                </div>
            </div>
    </body>
</html>
)=====";
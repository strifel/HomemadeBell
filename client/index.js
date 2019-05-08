const notifier = require('node-notifier');
const http = require('http');
const url = "";
let lastCheck = 0;

function sheduleCheck() {
    setTimeout(() => {
        http.get(url, (resp) => {
            var data = '';
            resp.on('data', (chunk) => {
                data += chunk;
            });
            resp.on('end', () => {
                if (parseInt(data) > lastCheck) {
                    notifier.notify({
                        title: "Homemadebell",
                        message: "Someone is there for you!",
                        sound: true,
                        wait: true
                    })
                }
                lastCheck = new Date().getTime() / 1000;
                sheduleCheck()
            });
        });
    }, 5000);
}

sheduleCheck();

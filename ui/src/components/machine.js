import React from 'react'

import config from '../config.js'

class Machine extends React.Component {
  constructor() {
    super();
    this.state = {
      state: null,
    };

    this.timer = null
  }

  componentDidMount() {
    // Exercise 4
    // Use `setInterval` to set a timer.
    // Call fetch_data() when the timer expires.

    this.fetch_data();
  }

  componentWillUnmount() {
    clearInterval(this.timer)
  }

  fetch_data() {
    fetch(config.machine_url + '/machine/state', { method: 'GET' })
      .then(res => res.json())
      .then((ms) => {
        // Exercise 3
        // Fetch the temperature from '/machine/temperature'
        this.setState({
          state: ms.state,
        })
      })
      .catch(console.log)
  }

  handle_action(action) {
    fetch(config.machine_url + '/machine/' + action, { method: 'POST' })
      .then(this.fetch_data())
      .catch(console.log)
  }

  machine_state() {
    return 'machine-' + this.state.state
  }

  render_button() {
    // Exercise 2
    // Show start or stop button, depending on this.state.state.

    return (
      <button onClick={() => this.handle_action('start')}>start</button>
    )
  }

  render() {
    return (
      <React.Fragment>
        <div className="content-box">
          <h1>Machine</h1>
        </div>
        <div className="content-box">
          <table>
            <tbody>
              <tr>
                <td>State:</td>
                <td className={this.machine_state()}>{this.state.state}</td>
              </tr>
            </tbody>
          </table>
        </div>
        <div className="content-box">
          {this.render_button()}
        </div>
      </React.Fragment>
    )
  }

}

export default Machine
